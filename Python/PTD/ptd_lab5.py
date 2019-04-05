# -*- coding: utf-8 -*-
"""
Created on Thu Dec 20 14:30:21 2018

@author: Paweł
"""
import pylab as py
import numpy as np
import scipy as sc

def sin(N):
    m=[0,1,1,0,0,1,1,1,0,0,0,1,0,1,0,1]
    
    tab_za=[]
    tab_zf=[]
    tab_zp=[]
    tab_san=[]
    tab_spn=[]
    xtA=[]
    ptA=[]
    xtP=[]
    ptP=[]
    mtA=[]
    mtP=[]
    mtF=[]
    sn1F=[]
    sn2F=[]
    x1tF=[]
    x2tF=[]
    ptF1=[]
    ptF2=[]
    ptF=[]
    
    h=130
    h2=-32
    h3=-32
    sumaA=0
    sumaP=0
    sumaF1=0
    sumaF2=0
    bit=0  
    A1=1
    A2=2
     
    T=1
     
    Fs=2000
    Tb=T/len(m)
    dt = T/Fs    
         
    t = np.arange(0,T,dt)
    
    fn1=(N+1)/Tb-0.5
    fn2=(N+2)/Tb
    fn=N*(1/Tb)

    N=T*Fs
    Tbp=N/len(m)
      
    for n  in range(0,N-1):
        if(n%Tbp==0 and n>0):
            bit=bit+1
        if(m[bit]==0):
            za=A1*np.sin(2*np.pi*fn*t[n])           
            zf=np.sin(2*np.pi*fn1*t[n])
            zp=np.sin(2*np.pi*fn*t[n])
            tab_za.append(za)
            tab_zp.append(zp)
            tab_zf.append(zf)
            tab_san.append(A2*np.sin(2*np.pi*fn*t[n]))
            tab_spn.append(zp)
            sn1F.append(zf)
            sn2F.append(np.sin(2*np.pi*fn2*t[n]))
        if(m[bit]==1):
            za=A2*np.sin(2*np.pi*fn*t[n])
            zf=np.sin(2*np.pi*fn2*t[n])
            zp=np.sin(2*np.pi*fn*t[n]+np.pi)
            tab_za.append(za)
            tab_zp.append(zp)
            tab_zf.append(zf)
            tab_san.append(za)
            tab_spn.append(np.sin(2*np.pi*fn*t[n]))
            sn1F.append(np.sin(2*np.pi*fn1*t[n]))
            sn2F.append(zf)
                   
    xtA=np.multiply(tab_za,tab_san)
    xtP=np.multiply(tab_zp,tab_spn)
    x1tF=np.multiply(tab_zf,sn1F)      
    x2tF=np.multiply(tab_zf,sn2F)
                
    (ptA)=calka(Tbp,sumaA,xtA,ptA)
    (ptP)=calka(Tbp,sumaP,xtP,ptP)
    (ptF1)=calka(Tbp,sumaF1,x1tF,ptF1)
    (ptF2)=calka(Tbp,sumaF2,x2tF,ptF2)
               
    for n in range(0,len(ptA)):
        if(ptA[n]<h):
            mtA.append(0)
        if(ptA[n]>=h):
            mtA.append(1)
        
    for n in range(0,len(ptP)):
        if(ptP[n]>=h2):
            mtP.append(0)
        if(ptP[n]<h2):
            mtP.append(1)
            
    ptF=np.subtract(ptF1,ptF2)    
    for n in range(0,len(ptF)):
        if(ptF[n]>=h3):
            mtF.append(0)
        if(ptP[n]<h3):
            mtF.append(1)

    return (m,t,za,zf,zp,tab_za,tab_zf,tab_zp,tab_san,xtA,ptA,mtA,xtP,ptP,mtP,x1tF,x2tF,ptF,mtF)
        
def calka(Tbp,suma,xt,pt):
    for n in range(0,len(xt)):
        if(n%Tbp==0 and n>0):
             suma=0
        suma=suma+xt[n]
        pt.append(suma)
    return pt

def wykres(s1,s2,lista):
    py.figure(figsize=(6, 2), dpi=100)
    py.plot(lista)
    py.ylabel(s1)
    py.title(s2)
    py.show()
         
    
(m,t,za,zf,zp,tab_za,tab_zf,tab_zp, tab_san,xtA,ptA,mtA,xtP,ptP,mtP,x1tF,x2tF,ptF,mtF)=sin(2)

wykres('Amplituda', 'ASK', tab_za)
wykres('Amplituda', 'ASK x(t)', xtA)
wykres('Amplituda', 'ASK p(t)', ptA)
wykres('Amplituda', 'ASK m^(t)', mtA)

wykres('Amplituda', 'PSK', tab_zp)
wykres('Amplituda', 'PSK x(t)', xtP)
wykres('Amplituda', 'PSK p(t)', ptP)
wykres('Amplituda', 'PSK m^(t)', mtP)

wykres('Amplituda', 'FSK', tab_zf)
wykres('Amplituda', 'FSK x1(t)', x1tF)
wykres('Amplituda', 'FSK x2(t)', x2tF)
wykres('Amplituda', 'FSK p(t)', ptF)
wykres('Amplituda', 'FSK m^(t)', mtF)

