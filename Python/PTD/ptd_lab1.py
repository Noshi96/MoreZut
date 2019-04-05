import pylab as py
import numpy as np
 

def zadanie1():
    f=100
    Fs=8000
    T=1
    dt=1.0/Fs
    t2=np.arange(0,T,dt)
    x=0
    tab_x=[]
    phi=np.pi
    for t in np.arange(0,T,dt):
        x=np.cos(2*np.pi*f*t + phi)*pow((t/2),0.12)
        tab_x.append(x)
        
    py.plot(t2,tab_x)
    py.title('Zad 1')
    py.show()
    return tab_x,t2
    


def zadanie2(tabzad1):
    Fs=8000
    T=1
    dt=1.0/Fs
    tab_z=[]
    tab_v=[]
    z=0
    t2=np.arange(0,T,dt)
    iterator=0
    for t in np.arange(0,T,dt):
        y=(np.power(t,2)/(t+1))
        z=((t/3)*np.abs((0.1*tabzad1[iterator])-((0.65/(t+1))*y)))
        tab_z.append(z)
        v=3*np.power(tabzad1[iterator],7)*np.sqrt(np.abs(y))
        tab_v.append(v)
        iterator=iterator+1
        
    py.plot(t2,tab_z)
    py.title('Zad 2 Przykład 1')
    py.show()
    
    py.plot(t2,tab_v)
    py.title('Zad 2 Przykład 2')
    py.show()
    return tab_z,t2

def zadanie3():
    T = 1 
    Fs = 4000
    
    dt=1.0/Fs
    tablica=[]
    u=0
    t2=np.arange(0,T,dt)
    
    for t in np.arange(0,T,dt):
        if(t>=0 and t<0.4):
            u=np.power(0.8,t)-1
            tablica.append(u)
        if(t>=0.4 and t<0.6):
            u=(1.8*t*np.cos(16*np.pi*(t/Fs)+np.pi))*-1
            tablica.append(u)
        if(t>=0.6 and t<0.8):
            u=0.72*t
            tablica.append(u)
        if(t>=0.8 and t<1):
            u=(0.29*np.power(t,8)*np.sin(31*np.pi*(t/Fs)))+0.55
            tablica.append(u)
            
    
    py.plot(t2,tablica)
    py.title('Zad 3')
    py.show()
    py.show()
    return(tablica,t2)       

def zadanie4(H,zad):
    Fs=10000
    T=1
    dt=T/Fs
    g=0
    t2=np.arange(0,T,dt)
    tab_g=[]
    
    for t in np.arange(0,T,dt):
        for p in range(1,H):
            g=g+((np.power(-1,p)/p)*((np.cos(p*np.pi*2*t))-1)*(np.sin(p*np.pi*t)))
        g=g*(2/np.pi)
        tab_g.append(g)
        
            
    py.plot(t2,tab_g)
    py.title('Zad 4 Przykład '+ zad)
    py.show()
    
    
    
(zad1_Tab,zad1_t)=zadanie1()
(zad2_Tab,zad2_t)=zadanie2(zad1_Tab)
(zad3_Tab,zad3_t)=zadanie3()    
zadanie4(2,'a)')
zadanie4(20,'b)')  
zadanie4(200,'c)')      
