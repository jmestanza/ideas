import numpy as np
import math 
t = int(input())
ans = []

good_ones = []
def solve2(level,last_decision, cum_sum, total,last_level,last_moves):
    if cum_sum == total:
        good_ones.append(last_moves)
        return
    elif level == last_level:
        # no llego al total es malardo
        return
    else:
        cs1 = last_moves + [+1]
        solve2(level+1,[+1],cum_sum + 2**level,total,last_level,cs1.copy())
        cs2 = last_moves + [-1]
        solve2(level+1,[-1],cum_sum - 2**level,total,last_level,cs2.copy())
        cs3 = last_moves + [0]
        solve2(level+1,[0],cum_sum,total,last_level,cs3.copy())
    return

def search_min_len(g_ones):
    minl = 100000000000
    min_len_path = []
    for i in range(len(g_ones)):
        if minl > len(g_ones[i]):
            minl = len(g_ones[i])
            min_len_path = g_ones[i].copy()
    return min_len_path

def solve(z):
    global good_ones
    good_ones = []
    if z != 0:
        last = int(math.ceil(np.log2(abs(z))))
        solve2(0,[0],0,z,last+1,[])
    else:
        good_ones.append([0])

    return good_ones.copy()


def makeequallen(x_solved,y_solved):
    diff_len = abs(len(x_solved) - len(y_solved))
    zeros = diff_len*[0]
    if len(x_solved) > len(y_solved):
        y_solved += zeros
    else:
        x_solved += zeros
    return x_solved.copy(),y_solved.copy()

def join_solutions(good_x,good_y):
    good_x_final = [] 
    good_y_final = []
    min_len_pair = 100000000000000
    for i in range(len(good_y)):
        for j in range(len(good_x)):      
            gx,gy = makeequallen(good_x[j].copy(),good_y[i].copy())
            bad_pair = False
            for k in range(len(gx)):
                if abs(gx[k]) == abs(gy[k]):
                    bad_pair = True
            if not bad_pair and min_len_pair>len(gx):
                good_x_final = gx.copy()
                good_y_final = gy.copy()
                min_len_pair = len(gx)
            
    return good_x_final.copy(),good_y_final.copy()                

def isocuppied(num):
    return True if (num == 1 or num == -1) else False

for l in range(t):
    x,y = [int(k) for k in input().split(" ")]
    x_solved = solve(x)
    y_solved = solve(y)
    
    final_x,final_y =  join_solutions(x_solved,y_solved)
    if ((x+y)%2==0):
        rta= "IMPOSSIBLE"
    else:
        rta = ""
        for i in range(len(final_x)):
            if final_x[i] == 0:
                rta += "S" if final_y[i] == -1 else "N"
            else:
                rta += "W" if final_x[i] == -1 else "E"

    ans.append(rta)


for i in range(len(ans)):
    print("Case #{}: {}".format(i+1,ans[i]))
