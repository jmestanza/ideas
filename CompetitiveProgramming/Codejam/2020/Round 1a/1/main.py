import numpy as np
t = int(input())

def process_strings(str_list, isSuffix): # tiene sentido si str_list no esta vacia
    if len(str_list) == 0: # por las dudas pero no deberia pasar
        return ""
    index_longest = -1
    longest = -1
    for i,str_ in enumerate(str_list):
        if longest<len(str_):
            index_longest = i
            longest = len(str_)

    longest_string = str_list[index_longest]
    ans = longest_string # es el optimo a menos uno de los de menor tamanio la cague
    if(isSuffix):
        for str_ in str_list:
            if not longest_string.endswith(str_):
                ans = "*"
    else:
        for str_ in str_list:
            if not longest_string.startswith(str_):
                ans = "*"
    return ans # esta ans es representativa de su conjunto

for l in range(t):
    str_cnt = int(input())

    pref = []
    suf = []
    middle = []
    for i in range(str_cnt):
        curr_str = input()
        pref_idx = 0
        suf_idx = len(curr_str)
        for j in range(len(curr_str)):
            if curr_str[j] == "*":
                pref_idx = j
                break
                
        for j in range(len(curr_str)):
            if curr_str[(len(curr_str)-1)-j] == "*":
                suf_idx = (len(curr_str)-1)-j
                break
        pref.append(curr_str[:pref_idx])
        suf.append(curr_str[suf_idx+1:])    
        aux = curr_str[pref_idx+1:suf_idx]
        if curr_str.count("*")>=2:
            middle.append(aux.replace("*","")) 
        # print("pref:", pref[i])
        # print("suf:" ,suf[i])
        # print("mid:" ,aux)
        

    ans_suf = process_strings(suf, 1)
    ans_pref = process_strings(pref, 0)

    if(ans_suf != "*" and ans_pref != "*"):
        ans = ans_pref+"".join(middle)+ans_suf
    else:
        ans = "*"
    print("Case #{}: {}".format(l+1,ans))

