import numpy as np

def store_mat(r):
    mat = []
    for i in range(r):
        row = [[1 if v=="@" else 0 for v in input()]]
        if i == 0:
            mat = np.array(row)
        else:
            mat = np.concatenate((mat,row),axis=0)
    return mat

def get_cum_sum(mat):
    cs_row = []
    total_chips = 0
    for i in range(len(mat)):
        curr_row = mat[i,:]
        for j in range(len(curr_row)):
            if curr_row[j] == 1:
                total_chips+=1
        cs_row.append(total_chips)
    return total_chips,cs_row

def get_tot_chips_and_cum_sums(mat,r,c):
    tot_chips,cs_row =get_cum_sum(mat)
    _,cs_col = get_cum_sum(mat.T)
    return tot_chips,cs_col,cs_row

def traverse_cases(d,ix,last,cnt_max,cnt):
    if(ix == len(d)):
        return 
    # ix es el indice
    print("traversing: ", d[ix], "con frecuencia: ",d[ix][1][0])
    for i in range(d[ix][1][0]): # frecuencia
        print("[",str(last),str(d[ix][1][1]+i),"]") # indice
        traverse_cases(d,ix+1,d[ix][1][1]+i+1,cnt_max,cnt+i)
    # faltaria guardar este traverse en una estructura de dato y listo el pollen
    
def get_interval_div(cs_row,slot_row):
    d = {}
    casos_reps = 0
    for i in range(len(cs_row)):
        if cs_row[i] % slot_row == 0:
            if cs_row[i] in d:
                d[cs_row[i]][0]+= 1 # incremento el numero de ocurrencias
                casos_reps+=1
            else:
                d[cs_row[i]] = [1,i] # num de ocurrencias e indice
            # no es necesariamente cierto que si me quedo con la primera ocurrencia es la decision buena
            # asi que hay que tener en cuenta todos los casos
            # croe que este es el error en la logica!!! :DDD

    aux = []
    # print(cs_row)
    # print(d.keys())
    for num in sorted(d.keys()):
        if d[num][0] >= 1: # si la freq con la que aparece el numero es mayor a 1
            aux.append(d[num][0])
    all_cases = np.prod(np.array(aux)) # si hay dos frecuencias: 2 y 4 , el resultante de casos es 8
     
    dictlist = []
    for key, value in d.items():
        temp = [key,value]
        dictlist.append(temp)
    print("cantidad de cases: ",all_cases)
    print("antes de entrar hay un dict con esta pinta ",dictlist)
    print("suma cumulativa ", cs_row)
#def traverse_cases(d,ix,last,cnt_max,cnt)
    traverse_cases(dictlist,0,0,all_cases,0)
    # aca deberia tener los b y last actualizados, asi que solo queda armar el intervalo
    return d

def test_intervals():
    chips_slots = [] 
    for a,b in interv_row:
        for x, y in interv_col:
            chips_slots.append(np.sum(mat[a:(b+1),x:(y+1)]))

    chips_slots = list(set(chips_slots)) # con set me quedo con los unicos
    # si len(chips_slots)> 1 por ej 2, significa que habria slot con distintos numero de chip, invalido
    # len(chips_slots) deberia ser siempre mayor a 0 (creo que es imposible que llegue aca y valga 0)
    return True if len(chips_slots) == 1 else False



total_ans = []

t = int(input())

for l in range(t):
    r,c,h,v = [int(k) for k in input().split(" ")]

    mat = store_mat(r)

    tot_chips, cs_col, cs_row = get_tot_chips_and_cum_sums(mat,r,c)
    ans = ""
    # si hago H cortes, tengo h+1 slots
    # en esos slots deberian ser en igual cantidad de chips para todos

    if tot_chips == 0:
        ans = "POSSIBLE"
    elif tot_chips % ( (h+1)*(v+1) ) != 0:
        ans = "IMPOSSIBLE"
    else:
        slot_row = tot_chips//(h+1) # lo que tiene que haber en cada SLOT si o si
        slot_col = tot_chips//(v+1) # sino, IMPOSSIBLE
        # realizo el corte y veo cuantos chips quedan
    
        interv_row = get_interval_div(cs_row,slot_row) # len deberia ser de h+1 (>=2 siempre)
        interv_col = get_interval_div(cs_col,slot_col) # len deberia ser de v+1 (>=2 siempre)
        
        
        if len(chips_slots)== 1: # si solo hay un elemento en el set, significa que se puede! (no hubo otros)
            ans = "POSSIBLE"
        else:
            ans = "IMPOSSIBLE"

    total_ans.append(ans)

aux = ""
for i in range(len(total_ans)):
    aux += "Case #{}: {}".format(i+1,total_ans[i])
    if i!= len(total_ans)-1:
        aux+= "\n"
    #print("Case #{}: {}".format(i+1,total_ans[i]))
print(aux)