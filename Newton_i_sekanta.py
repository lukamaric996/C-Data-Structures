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
