character = input()

init_positions = [int(x) for x in input().split(" ")]

R =  [init_positions[0],init_positions[1]]
C1 = [init_positions[2],init_positions[3]]
C2 = [init_positions[4],init_positions[5]]
C3 = [init_positions[6],init_positions[7]]

def dist_cops(x_c,y_c, x_r,y_r):
    return abs(x_c-x_r)+abs(y_c-y_r)


#---------next move-----------
cops = [C1,C2,C3]

if(character == "R"):
    cops = [C1,C2,C3,[0,0],[19,19],[0,19],[19,0]]

    #puedo correr en diagonal
    xr = R[0]
    yr = R[1]
    max_dist = -1
    min_dist = 10000
    pos_max_dist = [-100,-100]

    max_original_dist = -10
    min_dist = 10000
    min_dist_pos = []
    for cop in cops: 
        xcop = cop[0]
        ycop = cop[1]   
        distance = dist_cops(xcop,ycop,xr,yr)
        if distance < min_dist:
            min_dist = distance
            min_dist_pos = [xcop,ycop]

    xcop = min_dist_pos[0]
    ycop = min_dist_pos[1]

    for i in [-1,0,1]: # -1,0,1
        for j in [-1,0,1]:
            if( (0 <= xr+i) and (xr+i <= 19) and (0 <= yr+j) and (yr+j <=19)): # si es un mov valido
                distance = dist_cops(xcop,ycop,xr+i,yr+j) # distnacia al cop habiendome movido 
                if(distance>max_dist):
                    pos_max_dist = [xr+i, yr+j]
                    max_dist = distance

    print(pos_max_dist[0],pos_max_dist[1])
else:
    # cop 1 se mueve en x hasta igualar a jekill x
    # cop 2 se mueve en y hasta igualar a jekill y 
    # cop 3 se mueve en diagonal toma la mayor distancia entre x o y y acorta por ese caminos
    xr = R[0]
    yr = R[1]

    ans_cop = []
    for i,cop in enumerate(cops): 
        xcop = cop[0]
        ycop = cop[1]    
        if i == 0:
            # lo hago ir por x
            if not xr == xcop:
                xcop += 1 if xr>xcop else -1
            else:
                ycop += 1 if yr>ycop else -1

        elif i == 1:
            # lo hago ir por y
            if not yr == ycop:
                ycop += 1 if yr>ycop else -1
            else:
                xcop += 1 if xr>xcop else -1

        elif i == 2:
            # mueve en diagonal tomando la mayor distnaciaeentre  x oy
            if abs(xr-xcop)> abs(yr-ycop):
                xcop += 1 if xr>xcop else -1
            else:
                ycop += 1 if yr>ycop else -1
        ans_cop.append([xcop,ycop])

    a = ""
    for k,el in enumerate(ans_cop):
        if k < len(ans_cop):
            a += str(el[0]) + " " + str(el[1]) + " "
        else:
            a += str(el[0]) + " " + str(el[1]) 
    print(a)
