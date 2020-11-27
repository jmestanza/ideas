import math
import numpy as np
import scipy

def check_ineq(color,m1):
    cnt = 0
    for x_,y_ in color:
        if(y_>= m1*x_):
            cnt +=1
    return cnt

def check_ineq2(color,m1):
    cnt = 0
    for x_,y_ in color:
        if(y_<= m1*x_):
            cnt +=1
    return cnt



q = int(input())
for i in range(q):
    n = int(input())
    angles = []
    rojos = []
    blues = []
    a = []
    for i in range(n):
        [x,y,tipo] = input().split(" ")
        x = float(x)
        y = float(y)
        tipo = int(tipo)
        if tipo == 1:
            rojos.append([x,y])
        else:
            blues.append([x,y])
    
    separable = False
    
    eps = np.pi/100
    
    angles = np.linspace(-np.pi/2+eps,np.pi/2-eps,20) # esto tiene m negativos y positivos
    m_posibles = list(np.tan(angles))

    old_rojos = 0

    m_resultados = []

    for i in range(len(m_posibles)):
        m = m_posibles[i]
        cnt_rojos = check_ineq(rojos,m)
        cnt_blues = check_ineq(blues,m)

        m_resultados.append([m,cnt_rojos])
    max_resultados =max(l[1] for l in m_resultados)
    buenos = []
    for i in range(len(m_resultados)):
        if m_resultados[1] == max_resultados:
            buenos.append([m_resultados[0],m_resultados[1]])
    
    print("buenos",buenos)
    for j in range(len(buenos)):
            print(buenos[j])

    #print(max_resultados)        


        # if cnt_rojos == len(rojos) and cnt_blues == 0:
        #     separable = True
        # if cnt_blues == len(blues) and cnt_rojos == 0:
        #     separable = True

        # if separable == True:
        #     print("YES")
        #     break
    #for j in range(len(m_resultados)):
    #    print(m_resultados[j])

    if not separable:
        print("NO")
