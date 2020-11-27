import numpy as np

[w,h,a,b,m,c ] =[int(el) for el in input().split(" ")]

# primero mosaicos necesarios (sin cortar)
mosaicos_horizontal = np.ceil(w/a)
print(mosaicos_horizontal)

mosaicos_vertical = np.ceil(h/b)  
print(mosaicos_vertical)

# ahora me fijo cuanto tengo que cortar.
cut_horizontal = mosaicos_horizontal*a- w
print(cut_horizontal)

cut_vertical  = mosaicos_vertical*b - h
print(cut_vertical)


print("necesito:",mosaicos_vertical*mosaicos_horizontal)
need = mosaicos_vertical*mosaicos_horizontal
packs = np.ceil(need/10) 

init_money =packs*m

new_a = mosaicos_horizontal*a - cut_horizontal
new_b = mosaicos_vertical*b - cut_vertical

print("a'",new_a)
print("b'",new_b)

medio_perimetro = (new_a + new_b)
print(medio_perimetro)
cut_money = c*medio_perimetro
print(int(init_money+cut_money))