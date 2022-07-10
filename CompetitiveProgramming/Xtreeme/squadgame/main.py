import numpy as np
def str2arr(string):
    return [int(el) for el in string.split(',')]


def arr2string(arr):
    return ",".join(arr)

N = int(input())

all = []
for group in range(3):
    pos = []
    for i in range(N):
        [x, y] = [el for el in input().split(" ")]
        pos_aux = arr2string([y,x])
        print(pos_aux)
        pos.append(pos_aux)
    all.append(pos)


# gather the most near
def area(A, B, C):
    A = str2arr(A)
    B = str2arr(B)
    C = str2arr(C)
    AB = np.array([A[0] - B[0], A[1] - B[1]])
    AC = np.array([A[0] - C[0], A[1] - C[1]])
    return abs(np.cross(AB, AC)) / 2


while len(all) > 0:
    nice_comb = []
    globalArea = float('inf')
    for pos0 in all[0]:
        for pos1 in all[1]:
            for pos2 in all[2]:
                currArea = area(pos0, pos1, pos2)
                if currArea <= globalArea:
                    nice_comb = [pos0, pos1, pos2]
                    globalArea = currArea

    print(nice_comb)
    if len(nice_comb) == 0:
        break
    else:
        idx0 = all[0].index(nice_comb[0])
        idx1 = all[1].index(nice_comb[1])
        idx2 = all[2].index(nice_comb[2])
        all[0].pop(idx0)
        all[1].pop(idx1)
        all[2].pop(idx2)
        indexes = [str(el) for el in [idx0+1, idx1+1, idx2+1]]
        print(" ".join(indexes))