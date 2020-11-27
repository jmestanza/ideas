import numpy as np
[first_rule,second_rule] = [el for el in input().split(";")]
first_rule = [int(el) for el in first_rule]
second_rule = [int(el) for el in second_rule]

[N,M] = [int(el) for el in input().split(" ")]
main_mat = np.zeros((N,N)).astype(np.int8)

#first_rule => update(emptycells)
# second rule => update(live cells)


def empty_cell_logic(alive_mat,i,j,first_rule):
    shall_born = False

    for i_ in range(len(first_rule)):
        if first_rule[i_] == 1:
            if alive_mat[i][j] == (i_): # i_ para que sea como el enunciado 
                # que pasa si para un bit se cumple y para el resto no?
                # es un or o un and entre todos? supongo or
                shall_born |= True
    if shall_born:
        return 1
    else:
        return 0

    
def live_cell_logic(alive_mat,i,j,second_rule):
    shall_stay_alive = False

    for i_ in range(len(second_rule)):
        if second_rule[i_] == 1:
            if alive_mat[i][j] == (i_): # i_ para que sea como el enunciado 
                # que pasa si para un bit se cumple y para el resto no?
                # es un or o un and entre todos? supongo or
                shall_stay_alive |= True
    if shall_stay_alive:
        return 1
    else:
        return 0

def get_alive_neighbours(original_mat,i,j):
    count_alive = 0
    for di,dj in [[-1,0],[0,-1],[1,0],[0,1]]:
        di_eff = i+di
        dj_eff = j+dj
        if(di_eff<0):
            di_eff += N
        elif di_eff>(N-1):
            di_eff -= N
        
        if(dj_eff<0):
            dj_eff += N
        elif dj_eff>(N-1):
            dj_eff -= N

        count_alive += original_mat[di_eff,dj_eff]
    return count_alive
#for i in range(M): # por M generaciones hacer las cosas

for i in range(N):
    aux = input()
    main_mat[i,:] = np.array([int(el) for el in aux])

alive_mat = np.zeros_like(main_mat)
not_updated_mat = np.zeros_like(main_mat)


for z in range(M):
    #print("entrada iteracion: ",z)
    #print(main_mat)
    
    for i in range(N):
        for j in range(N):
            alive_mat[i,j] = get_alive_neighbours(main_mat,i,j)

    for i in range(N):
        for j in range(N):
            if main_mat[i,j] == 0:
                not_updated_mat[i,j] = empty_cell_logic(alive_mat,i,j,first_rule)
            else:
                not_updated_mat[i,j] = live_cell_logic(alive_mat,i,j,second_rule)
    
    main_mat = not_updated_mat.copy()
    print("iteracion: ",z)
    print("main_mat")
    for i in range(N):
        aux = ""
        str_list = [str(el) for el in main_mat[i,:]]
        aux = aux.join(str_list)
        print(aux)


            
#print(main_mat) 


#print("alivemat") 
#print(alive_mat)
#    solve(main_mat)
