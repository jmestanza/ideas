pieces = ["king","queen","rook","bishop","knight","pawn"]

f = open("pieces_position.json", "w")
f.write("{ \n")
f.write("\t \"pieces\":{\n")

idx = 0
for color in ["black","white"]:
    x = 24 if color == "black" else 24
    y = 20 if color == "black" else 20+60 # aca deberia haber un if
    for piece in pieces:
        idx += 1
        if(idx < 12):
            f.write(f"\t\t\"{color}_{piece}\":[{x},{y}],\n")
        else:
            f.write(f"\t\t\"{color}_{piece}\":[{x},{y}]\n")
        x += 66
f.write("\t},\n")
f.write("\t \"possible_moves_deltas\":{\n")        
idx = 0
delta = {}
delta["white_pawn"] = [[0,-1],[-1,-1],[1,-1],[0,-2]] 

# solo puede ir para abajo, esto es diferente en white
# en el primer turno peude avanzar 2 , y cuando come en diagonal

delta["black_rook"] = [[0,i] for i in range(1,8)]+[[j,0] for j in range(1,8)]+[[0,-i] for i in range(1,8)]+[[-j,0] for j in range(1,8)] # no puede saltar piezas!!

diagonal_pos = [[i,i] for i in range(-7,0)] + [[i,i] for i in range(1,8)]
diagonal_neg = [[i,-i] for i in range(-7,0)] + [[i,-i] for i in range(1,8)]

delta["black_bishop"] = diagonal_neg+diagonal_pos # no puede saltar piezas!!

delta["black_queen"] = delta["black_rook"]+delta["black_bishop"] # no puede saltar piezas!!

knight_moves = [[i,j] for i in [2,-2,1,-1] for j in [2,-2,1,-1]]

real_knight_moves = []
for move_x,move_y in knight_moves:
    if abs(move_x) != abs(move_y):
        real_knight_moves.append([move_x,move_y])

delta["black_knight"] = real_knight_moves
enroque_moves = [[0,3],[0,-4]]
delta["black_king"] = [[1, 1], [1, 0], [1, -1], [0, 1], [0, -1], [-1, 1], [-1, 0], [-1, -1]] + enroque_moves 

delta["black_pawn"] = [[0,1],[-1,1],[1,1],[0,2]] 
delta["white_rook"] = delta["black_rook"]
delta["white_bishop"] = delta["black_bishop"] # no puede saltar piezas!!
delta["white_queen"] = delta["black_queen"] # no puede saltar piezas!!
delta["white_knight"] = delta["black_knight"]
delta["white_king"] = delta["black_king"]




for color in ["black","white"]:
    for piece in pieces:
        idx += 1
        curr_possible = delta[color+"_"+piece]
        if(idx < 12):
            f.write(f"\t\t\"{color}_{piece}\":{curr_possible},\n")
        else:
            f.write(f"\t\t\"{color}_{piece}\":{curr_possible}\n")
            
        x += 66
f.write("\t}\n")
f.write("}\n")

f.close()

