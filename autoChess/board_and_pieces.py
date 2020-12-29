class chessPiece:
    def __init__(self,piece_name, pos, used_times):
        self.piece_name = piece_name
        self.pos = pos
        self.used_times = used_times

class chessBoard(): # chessBoard sobreescribe el init de chessPiece
    # a menos que llamemos a su init
    def __init__(self):
        self.board = [[[] for i in range(8)] for j in range(8)]
        self.ids = [[["void"] for i in range(8)] for j in range(8)]
        self.set_initial_ids()
        self.set_initial_board()
        
    def set_initial_ids(self):   
        self.ids[0] = ["black_rook","black_knight","black_bishop","black_queen","black_king","black_bishop","black_knight","black_rook"]
        for i in range(8):
            self.ids[1][i] = "black_pawn" 
        for i in range(4):
            for j in range(8):
                self.ids[2+i][j] = "void"
        for i in range(8):
            self.ids[6][i] = "white_pawn"
        self.ids[7] = ["white_rook","white_knight","white_bishop","white_queen","white_king","white_bishop","white_knight","white_rook"]

    def set_initial_board(self):
        for i in range(8):
            for j in range(8):
                self.board[i][j] = chessPiece(piece_name=self.ids[i][j],pos = [i,j],used_times=0)   

