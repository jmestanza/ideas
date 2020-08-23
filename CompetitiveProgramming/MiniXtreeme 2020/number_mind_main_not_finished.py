from number_mind_utils import *
n = int(input())
d = {}
for i in range(n):
    number, correct = [x for x in input().split(" ")]
    if not correct in d:
        d[correct] = [number]
    else:
        d[correct].append(number)


sure_ones_0_guess = guess_0_correct_logic(d["0"])
print(sure_ones_0_guess) # esto puede devolverme un arreglo con [] o  ["sureval"]

#sure_ones_1_guess = guess_1_correct_logic(d["1"],sure_ones_0_guess)

# print(sure_ones_1_guess)
# sure_ones_2_guess = guess_0_correct_logic(d["1"])
# print(sure_ones_2_guess)