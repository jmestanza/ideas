t = int(input())
ans = []

def search_brackets(var_str):
    izq = -1
    der = -1
    N = -1
    brackets = []
    nested_stat = False
    level_left = 0
    last_level = 0
    stack = {}
    # tengo un N,izq,der por nivel (es un stack)
    for i in range(len(var_str)):
        if var_str[i] == "(": 
            stack[level_left] = i
            last_level = level_left
            level_left += 1
        elif var_str[i] == ")":
            stack[level_right] = i

    return brackets

def not_nested_logic(aux_str,idx,brackets):
    last = ""
    now_N,now_izq,now_der,_ = brackets[idx]
    if idx == 0:
        first = aux_str[:now_izq-1]
    else:
        _,_,prev_der,_ = brackets[idx-1]    
        first = aux_str[prev_der+1:now_izq-1] # evito el )
    
    middle = now_N*enter(aux_str[now_izq+1:now_der]) # salto los "N(" y ")"
    
    if idx == len(brackets)-1:
        last = aux_str[now_der+1:]
    return first+middle+last

def nested_logic(aux_str,brackets,idx):
    n,i,d,_ = brackets[idx]
    between_brackets = aux_str[i+1:d] 
    return n*enter(between_brackets) # salto los "N(" y ")"           

def enter(new_str):
    ans = ""
    brackets = search_brackets(new_str)
    if len(brackets) == 0:
        return new_str
    else:
        for idx in range(len(brackets)):
            is_nested_bracket = brackets[idx][3]
            if is_nested_bracket:
                ans+= nested_logic(new_str,brackets,idx)
            else:
                ans+= not_nested_logic(new_str,idx,brackets)  
    return ans

for l in range(t):
    str_act = input()
    decoded = enter(str_act)
    print(decoded)

    N = decoded.count('N')
    S = decoded.count('S')
    W = decoded.count('W')
    E = decoded.count('E')

    i = 1
    j = 1
    i += (S-N)%1000000000
    j += (E-W)%1000000000

    ans.append([i,j])

for l,a in enumerate(ans):
    print("Case #"+str(l+1)+":",a[1],a[0])
