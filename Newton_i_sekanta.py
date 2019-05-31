###NEWTON

###NEWTON

import numpy as np

def newton_method(f, df1, df2, a, tol):
    x=np.inf
    n=0
    while abs(x-a)> tol:
        x=a
        a = x - df1(x)/df2(x)
        n=n+1
    print ('Ekstrem je u tocki: ', x)
    print ('Vrijednost funkcije u ekstremu iznosi: ', f(x))
    print('Broj iteracija do rjesenja iznosi:', n)
    
def f(x):
    return x**2 + 5*(x**3) - 2*(x**4) + 5*x
def df1(x):
    return 8*x + 15*(x**2) - 8*x**3 + 5
def df2(x):
    return 8 + 30*x - 24*x**2

newton_method(f,df1,df2,4,0.0001)


###SEKANTA


import matplotlib.pyplot as plt
import numpy as np

def metoda_sekante(f, df, x0, x1, x=5, e=0.0001):
    
    def call (f, x):
        return f(x)
    
    x = x0
    x0 = np.inf
    n = 1
    df_x1 = call(df, x1)
    
    while abs(x-x0) > e:
        n += 1
        x0 = x
        df_x0 = call(df, x0)
        x = x0-df_x0*(x0-x1)/(df_x0-df_x1)
        df_x1 = df_x0
        x1 = x0
    print('Ekstremna vrijednost iznosi: ', x)
    print('Funkcija u ekstremnoj vrijednosti iznosi: ', call(f, x))
    print('Broj iteracija do rjesenja iznosi:', n)
    
def f(x):
    return 10*x**3 + 3*x**2 + 2*x + 2

def df(x):
    return 30*x**2 + 6*x + 2

metoda_sekante(f, df, -5, 5)

x = np.linspace(-1,1,1000)
plt.plot(x,f(x),'r')
plt.plot(x,df(x),'b')
plt.show()


#2D GRAFIKA

import numpy as np
import matplotlib.pyplot as plt

x=[0,3,3,3,0,3,3,0]
y=[0,0,2,2,2,2,4,4]

x1=[4,6,6]
x2=[2,4,0]

x3=[0,3,3,0,0]
x4=[0,0,4,4,0]

x5=[4,6,6,4,4,6]
x6=[0,0,2,2,4,4]

fig=plt.figure()
fig.suptitle("31.5.2019")

graf=fig.add_subplot(121)
line_up,=plt.plot(x,y,"r-",label="datum")
line_up,=plt.plot(x1,x2,"r-")
plt.legend(loc=1)
graf.set_xlabel("datum")



graf=fig.add_subplot(122)
line_up,=plt.plot(x3,x4,"r", label="mjesec")
line_down,=plt.plot(x5,x6,"r")
plt.legend(loc=1)
graf.set_xlabel("mjesec")





'''
NEWTON
Ako možemo izračunati vrijednosti funkcije f
 i vrijednosti derivacije funkcije f
 i ako znamo neki 𝑥𝑖 koji je blizu traženog korijena,
 možemo nelinearnu funkciju f u okolini točke
(𝑥 , f(𝑥𝑖)) zamijeniti pravcem najsličnijim
toj funkciji – tangentom


SEKANTA


Pretpostavimo da su nam poznate dvije točke 𝑥1 i 𝑥2 koje su blizu traženog
korijena, tada možemo funkciju 𝑓 zamijeniti pravcem kroz točke (𝑥1, 𝑓(𝑥1)) i
(𝑥2, 𝑓(𝑥2)) tj. sekantom. 


'''
