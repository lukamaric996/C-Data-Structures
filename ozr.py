##1. zadatak

#1.Procijenite apsolutnu pogrešku pri izračunavanju volumena idealnog plina formulom V = nRt/P

from math import *

Tx=280
dT=0.2
Px=101325
dP=20
nx=100
dn=0.1
R=8.3144621

fun=(nx*R*Tx)/Px

apsgr=abs((R*Tx)/Px)*dn + abs((nx*R)/Px)*dT + abs((-1/Px**2)*(nx*R*Tx))*dP

relgr = apsgr/abs(fun)
print("Apsolutna pogreska iznosi: ", apsgr)
print('Relativna: ', relgr)




#3.zad
#3.Aproksimirajte linearnim splajnom na 15 numeričkih 
#čvorova funkciju  na intervalu [-5,5]. 
#Odredite relativnu pogrešku aproksimacije u čvoru 2.31.
#Nacrtajte graf funkcije  i dobiveni kubični spline na intervalu

from numpy import *
from scipy import interpolate as i #interp1d
import pylab as py

def fun(x):
    return sin(x)-x


x15=linspace(-5,5, 15)
s15=i.interp1d(x15,fun(x15),kind="linear")
aps15=abs(fun(2.31)-s15(2.31))
rel15=aps15/abs(fun(2.31))

print("relativna greska u 2.31 na 15 cvorova",rel15)

xd=linspace(-5,5,1000)
py.plot(xd,fun(xd),'b')
py.plot(xd,s15(xd),'r')
py.show()



##2. zadatak
# 2.Izračunajte apsolutnu uvjetovanost funkcije
from math import *

x0=1.12

def f(x):
    return sqrt(x**2+1)

Cabs=abs(x0/(sqrt(x0**2+1)))
Crel=abs((x0/f(x0)) * (x0/(sqrt(x0**2+1))))

print("Apsolutna uvjetovanost: ", Cabs)
print("Relativna uvjetovanost: ", Crel)

#4.zadatak
##4.Odredite polinom p koji zadovoljava uvjete:                             
#p(1.13)=4., p'(1.13)=1., p(3.1)=3.
#Odredite vrijednost p(2.12)

from numpy import *
from numpy import linalg as l#rjesavanje sustava
from numpy.polynomial import polynomial as p#polinome

A=array([[1,1.13,1.13**2],[0,1,2*1.13],[1,3.1,3.1**2]])
b=array([4.,1.,3.])
ipol=l.solve(A,b)

print(ipol)
#provjera uvjeta
print(p.polyval(1.13,ipol))
print(p.polyval(1.13,p.polyder(ipol)))
print(p.polyval(3.1,ipol))
print(p.polyval(2.12,ipol)) #vrijednost polinoma u 2.12


###5. LINEARNA OVISNOST

from numpy import *

P=array([352, 373, 411, 441, 462, 490, 529, 577, 641, 692, 743])
Tr=array([146, 153, 177, 190, 205,208, 227, 238, 268, 274,300])
koef=polyfit(P,Tr,1)

def funR(x):
    return koef[0]*x+koef[1]

print("Procjena vrijednosti troskova u tisucama kad bi se proizvodilo 470 tona: ",funR(470))