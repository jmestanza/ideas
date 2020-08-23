# l = []
# l.append(['8'])
# l.append(['3', '7', '8'])
# l.append(['4', '5'])
# l.append(['0'])
# l.append(['2', '4', '8'])
# l.append(['0', '1', '5'])
# l.append(['0', '1', '6'])
# l.append(['2', '5'])
# l.append(['2', '7'])
# l.append(['2', '8'])
# l.append(['0', '6', '9'])
# l.append(['0', '4', '7'])

def search_sures(l):
    sure_ones_idx = []
    sure_ones = []
    for i in range(len(l)):
        if(len(l[i])==1):
            sure_ones_idx.append(i) # guardo el indice de lo super sure
            sure_ones.append(l[i][0])
    return sure_ones_idx,sure_ones


def get_sure_ones_list(l):
    for _ in range(10): # a lo sumo podria sacar 10 numeros en el mejor caso
        sure_ones_idx,sure_ones = search_sures(l)
        for i in range(len(l)):
            if not i in sure_ones_idx: # si no estoy seguro saco los seguros
                for el in sure_ones:
                    if el in l[i]:
                        l[i].remove(el)

    return l.copy()

def get_transposed_matrix(matrix):
    rows = len(matrix)
    cols = 12
    mat = []
    for i in range(rows): # numeros de 12 digitos en d["1"]
        mat.append(list(matrix[i])) 
    mat2 = []
    for j in range(cols):
        aux = []
        for i in range(rows):
            aux.append(mat[i][j]) 
        mat2.append(aux)
    return mat2

def guess_0_correct_logic(matrix_guess_0):
    mat2 = get_transposed_matrix(matrix_guess_0)
    # filas => digito iesimo
    possible_good_ones = []
    for i in range(len(mat2)):    
        good_ones = [str(x) for x in range(10)] # inocentemente del 0 al 9 son buenos
        wrong_ones = list(set(mat2[i])) # saco los que me di cuenta que eran malos
        for el in wrong_ones:
            good_ones.remove(el)
        possible_good_ones.append(good_ones)
    
    updated_sure_ones = get_sure_ones_list(possible_good_ones)
    return updated_sure_ones


def get_sure_indexes_after_guess(a):
    sure_idx = []
    for i,el in enumerate(a):
        if len(el) > 0 :
            sure_idx.append(i)
    return sure_idx

def guess_1_correct_logic(matrix_guess_1,sure_guesses_0):
    mat2 = get_transposed_matrix(matrix_guess_1)
    idx_not_to_it = get_sure_indexes_after_guess(sure_guesses_0)
    # filas => digito iesimo
    possible_good_ones = []
    # ahora tengo que filtrar los que estoy seguro desde guesses 0
    
    # for i in range(len(mat2)):    
    #     good_ones = [str(x) for x in range(10)] # inocentemente del 0 al 9 son buenos
    #     wrong_ones = list(set(mat2[i])) # saco los que me di cuenta que eran malos
    #     for el in wrong_ones:
    #         good_ones.remove(el)
    #     possible_good_ones.append(good_ones)
    
    # updated_sure_ones = get_sure_ones_list(possible_good_ones)
    # return updated_sure_ones
    return possible_good_ones
