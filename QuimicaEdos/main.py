import numpy as np
import matplotlib.pyplot as plt
T1 = 303
kA_T1 = 27.4 # unidades raras
Ea = 11593
R = 1.987
T2 = 323
kP_T2 = 10132.5
dHrxn = -11750
P0 = 1.8
T = 423

FA0 = 100000 # unidad extraña

# cuanto W necesito para alcanzar x = 0.9 ?
step = 1e-4
x = np.arange(0,0.9+step,step)

kA_T = kA_T1 * np.exp((Ea / R) * (1 / T1 - 1 / T))
kP_T = kP_T2 * np.exp((dHrxn / R) * (1 / T2 - 1 / T))

ra_prima = []
W = []
P = []

Y_0 = 1
PA_0 = P0 * 0.25 * Y_0
PB_0 = P0 * 0.25 * 3 * Y_0
PC_0 = 0
PD_0 = 0
P.append(P0)
ra_prima_0 = kA_T * ((PA_0 ** 2) * PB_0 - PC_0 * PD_0 / kP_T)
ra_prima.append(ra_prima_0)
W.append(0)

for i in range(0,len(x)-1):
    W.append(0)
    P.append(0)
    W[i+1] = W[i] + (FA0/(ra_prima[i]))*(x[i+1]-x[i]) # actualizacion
    P[i+1] = P[i]-0.00045*(1-0.125*x[i])*(P0**2)*(W[i+1]-W[i])/(2*P[i])
    y = P[i]/P0
    PA = P0*0.25*(1-x[i])*y/(1-0.125*x[i])
    PB = P0*0.25*(3-0.5*x[i])*y/(1-0.125*x[i])
    PC = P0*0.125*x[i]*y/(1-0.125*x[i])
    PD = PC
    ra_prima.append(kA_T * ((PA ** 2) * PB - PC * PD / kP_T))
    print(P[i])

plt.plot(W)
plt.show()