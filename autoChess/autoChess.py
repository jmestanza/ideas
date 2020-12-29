import pygame
import itertools
import json

from board_and_pieces import chessPiece,chessBoard


debug_flag = True

class chessGame():
    def __init__(self):
        #settings
        self.tile_size = 50
        self.width, self.height = 8*self.tile_size, 8*self.tile_size

        self.mouse_clicked = False
        self.done = False
        self.curr_turn = "white" # empiezan las blancas
        self.black_moves = []
        self.white_moves = []
        self.src_move = True

        self.src_pos = None
        self.dst_pos = None

        self.white_graveyard = []
        self.black_graveyard = []

        self.game_state = "playing"
        self.castling = False

        self.main_board = chessBoard()

        self.screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("AutoChess")

    def reset_board(self):
        self.main_board.set_initial_ids()
        self.main_board.set_initial_board()

    def run_game(self):
        self.reset_board()
        self.draw_board()
        while not self.done:
            self.check_event_queue()
            self.draw_board()
            if self.game_state == "playing":
                self.check_win()
            else:
                wanna_play = input("Quiere jugar otra partida? y/n:")
                if wanna_play == "y":
                    self.game_state = "playing"
                    self.reset_board()
            self.update_screen()


    def move_piece(self):
        print(f"voy de {self.src_pos} a {self.dst_pos}")
        print(f"o sea de {self.get_piece_name(self.src_pos)} a {self.get_piece_name(self.dst_pos)}")

        src_cnt = self.get_piece_used_times(self.src_pos)
        src_str = self.get_piece_name(self.src_pos)

        if self.curr_turn == "white" and "black" in self.get_piece_name(self.dst_pos):
            self.black_graveyard.append(self.get_piece_name(self.dst_pos))
        elif self.curr_turn == "black" and "white" in self.get_piece_name(self.dst_pos):
            self.white_graveyard.append(self.get_piece_name(self.dst_pos))

        self.main_board.board[self.src_pos[0]][self.src_pos[1]] = chessPiece(piece_name="void",pos = self.src_pos,used_times = 0) # supongo 0?
        self.main_board.board[self.dst_pos[0]][self.dst_pos[1]] = chessPiece(piece_name=src_str,pos = self.dst_pos, used_times= src_cnt+1) 

        print("despues del movimiento:")
        print(f"en src: {self.get_piece_name(self.src_pos)} y en dst: {self.get_piece_name(self.dst_pos)}")

        # self.print_board()

    def append_move(self):
        if self.curr_turn == "white":
            self.white_moves.append(f"{self.src_pos} => {self.dst_pos}")
        else:
            self.black_moves.append(f"{self.src_pos} => {self.dst_pos}")

    def check_event_queue(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.done = True    
            if event.type == pygame.MOUSEBUTTONDOWN:
                if self.game_state == "playing": 
                    if not self.mouse_clicked:
                        self.mouse_clicked = True 
                        # solo nos importa cuando es clickeado, que no vuelva a entrar mientras lo este
                        j_,i_ = pygame.mouse.get_pos()
                        if self.src_move:
                            self.src_i,self.src_j = i_//self.tile_size, j_//self.tile_size 
                            self.src_pos = self.src_i,self.src_j
                            
                            if self.check_src_move():
                                self.src_move = False
                        
                        else:
                            self.dst_i,self.dst_j = i_//self.tile_size, j_//self.tile_size 
                            self.dst_pos = self.dst_i,self.dst_j
                            
                            if self.check_dst_move():
                                self.move_piece() # excepto cuando estoy enrocando, muevo dos piezas
                                # y ni siquiera de src a dst :Ccc

                                self.src_move = True
                                
                                # antes de pasarle el turno hacemos un check border pawn y elegimos la pieza
                                piece_to_replace = self.check_border_pawn()
                                if piece_to_replace != "void":
                                    self.main_board.board[self.dst_pos[0]][self.dst_pos[1]] = chessPiece(piece_name=piece_to_replace,pos = self.dst_pos, used_times= self.get_piece_used_times(self.dst_pos)) 

                                # terminamos el turno

                                if self.curr_turn == "white":
                                    self.curr_turn = "black"
                                    self.white_moves.append(f"{self.src_pos} => {self.dst_pos}")
                                else:
                                    self.curr_turn = "white"
                                    self.black_moves.append(f"{self.src_pos} => {self.dst_pos}")
                                    
                                print("Ahora es turno de : ",self.curr_turn)

                            if self.castling:
                                # tengo que fijarme si es de izquierda a derecha o de derecha a izquierda

                                delta_j = self.dst_pos[1] - self.src_pos[1]
                                if delta_j > 0 : # voy a la derecha, es corto
                                    #rey siempre se mueve 2 a la derecha, torre a la izquierda de esta pos
                                    src_king = self.src_pos
                                    src_rook = self.dst_pos

                                    self.src_pos = src_king
                                    self.dst_pos = src_king[0],src_king[1]+2

                                    self.append_move()    
                                    self.move_piece()


                                    self.src_pos = src_rook
                                    self.dst_pos = src_king[0],src_king[1]+1
                                    self.move_piece()

                                    self.append_move()    

                                    
                                else: # es largo a la izquierda
                                    #rey siempre se mueve 2 a la izquierda, torre a la derecha de esta pos
                                    src_king = self.src_pos
                                    src_rook = self.dst_pos

                                    self.src_pos = src_king
                                    self.dst_pos = src_king[0],src_king[1]-2

                                    self.append_move()    
                                    self.move_piece()

                                    self.src_pos = src_rook
                                    self.dst_pos = src_king[0],src_king[1]-1
                                    
                                    self.append_move()    
                                    self.move_piece()
    
                                if self.curr_turn == "white":
                                    self.curr_turn = "black"
                                    # la anotacion depende de cual fue la realizada si la larga o la corta
                                    # self.white_moves.append(f"")
                                else:
                                    self.curr_turn = "white"
                                    # la anotacion depende de cual fue la realizada si la larga o la corta
                                    # self.black_moves.append(f"")
                                    
                                print("Ahora es turno de : ",self.curr_turn)

                                self.castling = False


            if event.type == pygame.MOUSEBUTTONUP:
                self.mouse_clicked = False        


    def check_border_pawn(self):
        piece_to_replace = "void"
        if self.curr_turn == "white":
            for i in range(8):
                if "white_pawn" == self.get_piece_name([0,i]):
                    print("Sus piezas muertas son:")
                    print(self.white_graveyard)
                    piece_to_replace = input("Cual de sus white piezas quiere revivir?")
        else:
            for i in range(8):
                if "black_pawn" == self.get_piece_name([7,i]):
                    print("Sus piezas muertas son:")
                    print(self.black_graveyard)
                    piece_to_replace = input("Cual de sus white piezas quiere revivir?")
        return piece_to_replace
        
    def print_board(self):
        ans = ""
        for i in range(8):
            for j in range(8):
                ans += self.main_board.board[i][j].piece_name + " " 
            ans += "\n"
        print(ans)

    def check_win(self):
        king_count = 0
        king_list = []
        for i in range(len(self.main_board.board)):
            for j in range(len(self.main_board.board[0])):
                if "king" in self.get_piece_name([i,j]):
                    king_count +=1
                    king_list.append(self.get_piece_name([i,j]))
        if king_count == 1:
            print(king_list[0][:5], "wins!")
            self.game_state = "win"

    def check_src_move(self):
        if debug_flag:
            print(f"Estoy en {self.src_pos}")
        # cuando estoy en src solo tengo que cuidarme que las piezas sean mias
        # salvo que sea enroque...
        valid_move = None
        if debug_flag:
            print("curr turn:",self.curr_turn)
            print("self.get_piece_name(self.src_pos) = ",self.get_piece_name(self.src_pos))
        if self.curr_turn in self.get_piece_name(self.src_pos):
            valid_move = True
        else:
            valid_move = False

        if debug_flag:
            print(f"Es una movida valida? {valid_move}")
        return valid_move
   
    def check_possible_moves(self,delta_moves):
        valid_possible_move = False
        for dx,dy in delta_moves: # croe uqe no habria que chequear que se vaya del tablero por los clicks              
            if (self.dst_pos[0] - self.src_pos[0]) == dy and (self.dst_pos[1]-self.src_pos[1]) == dx:  
                print(f"movimiento valido con dx={dx}, dy={dy}!!")                          
                valid_possible_move = True
                break
        return valid_possible_move

    def get_piece_name(self,pos):
        return self.main_board.board[pos[0]][pos[1]].piece_name
    
    def get_piece_used_times(self,pos):
        return self.main_board.board[pos[0]][pos[1]].used_times
    

    def check_pawn_possible_move(self): 
        print("entre a check pawn possible move")
        valid_move = None
        if self.curr_turn == "white":
            if self.get_piece_used_times(self.src_pos) == 0: # first pawn move of his life (counter of uses for pawns)
                valid_move = self.check_possible_moves([[0,-1],[0,-2]])
            else:
                if self.get_piece_name(self.dst_pos) == "void":
                    valid_move = self.check_possible_moves([[0, -1]])
                elif "black" in self.get_piece_name(self.dst_pos):
                    valid_move = self.check_possible_moves([[-1, -1], [1, -1]])
        else:
            if self.get_piece_used_times(self.src_pos) == 0: # first pawn move
                valid_move = self.check_possible_moves([[0,1],[0,2]])
            else:
                if self.get_piece_name(self.dst_pos) == "void":
                    valid_move = self.check_possible_moves([[0, 1]])
                elif "white" in self.get_piece_name(self.dst_pos):
                    valid_move = self.check_possible_moves([[-1, 1], [1, 1]])

        print("sali de check possible pawn con ",valid_move)
        return valid_move

    def check_no_jump_rook(self):
        collide = False
        delta_i_total = self.dst_pos[0] - self.src_pos[0]
        delta_j_total = self.dst_pos[1] - self.src_pos[1]
        if abs(delta_i_total)>0 and delta_j_total == 0:
            di = delta_i_total//abs(delta_i_total)
            for i in range(1,abs(delta_i_total)):
                target_piece = self.get_piece_name([self.src_pos[0]+i*di,self.src_pos[1]])
                if "white" in target_piece or "black" in target_piece:
                    collide = True           
        elif abs(delta_j_total)>0 and delta_j_total == 0: # hubo delta j 
            dj = delta_j_total//abs(delta_j_total)
            for i in range(1,abs(delta_j_total)):
                target_piece = self.get_piece_name([self.src_pos[0],self.src_pos[1]+i*dj])
                if "white" in target_piece or "black" in target_piece:
                    collide = True    
        return collide

    def check_no_jump_bishop(self):
        collide = False
        delta_i_total = self.dst_pos[0] - self.src_pos[0]
        di = delta_i_total//abs(delta_i_total)
        delta_j_total = self.dst_pos[1] - self.src_pos[1]
        dj = delta_j_total//abs(delta_j_total)

        for i in range(1,abs(delta_i_total)):
            target_piece = self.get_piece_name([self.src_pos[0]+di*i,self.src_pos[1]+dj*i])
            if "white" in target_piece or "black" in target_piece:
                print("hubo collide en bishop:")
                print(target_piece," ",[self.src_pos[0]+di*i,self.src_pos[1]+dj*i])
                collide = True           

        return collide
    def check_no_jump_queen(self):
        collide = False
        delta_i_total = self.dst_pos[0] - self.src_pos[0]
        delta_j_total = self.dst_pos[1] - self.src_pos[1]
        if delta_i_total == 0 or delta_j_total == 0:
            # la reina se mueve como torre
            if debug_flag:
                print("la reina se mueve como torre")
            collide = self.check_no_jump_rook()
        else:
            if debug_flag:
                print("la reina se mueve como alfil")
    
            # la reina se mueve como alfil
            collide = self.check_no_jump_bishop()
        return collide

    def check_no_jump(self): # deberian haber 0 piezas en mi forma de avanzar para que sea valido
        collide = False
        # if self.curr_turn == "white":            
        if "rook" in self.get_piece_name(self.src_pos):
            collide = self.check_no_jump_rook()
        elif "bishop" in self.get_piece_name(self.src_pos):
            print("estoy en caso bishoop!!!")
            collide = self.check_no_jump_bishop()
        elif "queen" in self.get_piece_name(self.src_pos):
            collide = self.check_no_jump_queen()

        return collide

    def check_dst_move(self):
        
        print(f"Entre con {self.dst_pos}")
        f = open("pieces_position.json")
        data = json.load(f)
        # puedo ir al enemigo, no puedo ir sobre mis propias unidades
        # y que sea valido el movimiento para la pieza
        print("chequeando dst move")
        valid_move = None
        if self.curr_turn in self.get_piece_name(self.dst_pos):
            valid_move = False # si a donde me voy a mover, es a una de mis piezas, es xq quiero cambiar de pieza
            from_piece = self.get_piece_name(self.src_pos) 
            from_uses =  self.get_piece_used_times(self.src_pos)
            target_piece = self.get_piece_name(self.dst_pos)
            target_uses = self.get_piece_used_times(self.dst_pos)

            if from_piece == self.curr_turn+"_king" and target_piece == self.curr_turn+"_rook":
                if from_uses == 0 and target_uses == 0:
                    clear = True
                    delta_j = self.dst_pos[1] - self.src_pos[1]
                    dj = delta_j//abs(delta_j)
                    for i in range(1,abs(delta_j)):
                        curr_target = self.get_piece_name([self.src_pos[0],self.src_pos[1]+i*dj])
                        if "white" in curr_target or "black" in curr_target:
                            clear = False
                    if clear:
                        # que no haya nada en el medio y que segun sea, se muevan las piezas
                        # (es distinto para las negras que para las blancas el desplazamiento)
                        # logica de enroque!
                        print("Se dio la situacion de enroque")
                        self.castling = True
                
            else: # cuando cambio de piezas..
                self.src_pos = self.dst_pos 

        else:
            if "pawn" in self.get_piece_name(self.src_pos):
                valid_move = self.check_pawn_possible_move()
            else:
                jumps_pieces = self.check_no_jump()
                is_possible_move = self.check_possible_moves(data["possible_moves_deltas"][ self.get_piece_name(self.src_pos)])
                print("Hay collide saltando?",jumps_pieces)
                print("Es un movimiento posible???", is_possible_move)
                valid_move = is_possible_move and not jumps_pieces
        return valid_move

    def draw_board(self):
        BROWN = pygame.Color('brown1') 
        YELLOW = pygame.Color('yellow')
        for i in range(8):
            for j in range(8):
                rect = (j*self.tile_size,i*self.tile_size,self.tile_size,self.tile_size)
                
                if self.get_piece_name([i,j]) == "void":
                    pygame.draw.rect(self.screen, BROWN if (i+j)%2 == 0 else YELLOW , rect)
                else:
                    self.draw_piece(self.get_piece_name([i,j]),i,j)

    def draw_piece(self,piece_name,tile_x,tile_y):
        f = open("pieces_position.json")
        data = json.load(f)
        pos_x, pos_y = data["pieces"][piece_name]
        image = pygame.image.load("chess_pieces.bmp")
        w, h = image.get_width(), image.get_height()
        scale = 2.5
        scaled_image = pygame.transform.smoothscale(image,(int(w/scale),int(h/scale)))        
        origin_piece = (self.tile_size*tile_y,self.tile_size*tile_x)
        piece_cut = pygame.Rect((pos_x,pos_y), ( int(image.get_width()/21), int(image.get_height()/7.5) )) # 7.5
        self.screen.blit(scaled_image, origin_piece, piece_cut,pygame.BLEND_ALPHA_SDL2)

    def update_screen(self):
        pygame.display.flip()


# log de thoughts:

# thoughts 1:
# -excepciones: 
#   -que se reincie el src si clickeo en una pieza mia (aunque podria hacer enroque, no?...)
#   - plot twist: el enroque puede ser hardcore de programar bien... (tendria que saber si hay jaque
#  si lo hace, y no dejar que lo haga...?)
#   -creo que toque en cualquier lado y se selecciono una pieza? (... no se repitio)

# thoughts 2:
#   -lo del enroque lo dejo asi, y si tengo ganas lo mejoro despues
#   - por ahora el enroque funciona agarrando el rey y despues la torre, al reves no funciona
#   -faltaria poder girar el tablero para verlo segun la perspectiva del que juega
#   -mejorar la interfaz (es malisima), poner graveyard, movimientos, y
#   cuando este haciendo eso chequear que no clickee fuera del tablero
#   -conectividad
#   -falta peon al paso y creo que la torre debe estar buggeada con lo del enroque


chess = chessGame() 

chess.run_game()

