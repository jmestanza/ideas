import numpy as np
t = int(input())
ans = []
for l in range(t):
    str_cnt = int(input())
    ans.append("*")


for i in range(len(ans)):
    print("Case #{}: {}".format(i+1,ans[i]))
