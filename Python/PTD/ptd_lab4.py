# -*- coding: utf-8 -*-
import pylab as py
import numpy as np
import scipy as sc






dB=3
def rysowanie(fmin,fmax,dB):
    xposition1 = [fmin,fmax]
    for xc in xposition1:
        py.axvline(x=xc, color='r', linestyle='--')
    
    yposition1 = [dB]
    for yc in yposition1:
        py.axhline(y=yc, color='r', linestyle='--')
    

def widmo(dft_tab):
    tab_log=[]
    M=0
    tab_wynik2=[]
    N=len(dft_tab)
    
    for k in range(0,int(N/2)):
        M=np.sqrt(np.power(dft_tab[k].real,2)+np.power(dft_tab[k].imag,2))
        tab_wynik2.append(M)
    return (tab_wynik2, tab_log)


def szerokosc_pasma(lista):
    dB=3
    tablica_minmax=[]
    for i in range (len(lista)):
        if lista[i]>=dB:
            tablica_minmax.append(i)
    if(tablica_minmax[0]==0):
        ffmin=tablica_minmax[1]
    else:
        ffmin=tablica_minmax[0]   
    ffmax=tablica_minmax[len(tablica_minmax)-1]  
    WW=ffmax-ffmin
    return (WW,ffmin,ffmax)


def sin():
    m=[0,1,1,0,0,1,1,1,0,0,0,1,0,1,0,1]
    
    tab_za=[]
    tab_zf=[]
    tab_zp=[]
    
    
    A1=1
    A2=2
    
    N=2  
    T=1
    
    Fs=2000
    Tb=2
    dt = T/Fs    
         
    t = np.arange(0,T,dt)
    
    
    fn1=(N+1)/Tb-0.5
    fn2=(N+2)/Tb
    fn=N*(1/Tb)

    
    N=T*Fs
    Tbp=N/len(m)
    Tb=T/len(m)
    
    
    for bit in range(0,len(m)):
       for n in range(0,N-1):
           if(n%Tbp==0):
               if(m[bit]==0):
                   za=A1*np.sin(2*np.pi*fn*t[n])
                   zf=np.sin(2*np.pi*fn1*t[n])
                   zp=np.sin(2*np.pi*fn*t[n])
                   tab_za.append(za)
                   tab_zp.append(zp)
                   tab_zf.append(zf)
               if(m[bit]==1):
                   za=A2*np.sin(2*np.pi*fn*t[n])
                   zf=np.sin(2*np.pi*fn2*t[n])
                   zp=np.sin(2*np.pi*fn*t[n]+np.pi)
                   tab_za.append(za)
                   tab_zp.append(zp)
                   tab_zf.append(zf)
    return (m,t,za,zf,zp,tab_za,tab_zf,tab_zp)


(m,t,za,zf,zp,tab_za,tab_zf,tab_zp)=sin()
py.figure(figsize=(6, 2), dpi=100)
py.plot(tab_za)

py.ylabel('Amplituda')
py.title('ASK')
py.show()

za1fft=sc.fft(tab_za)
(zad_11za, zad_11za_log)=widmo(za1fft)

py.semilogx(zad_11za)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji za')
py.show()


py.figure(figsize=(6, 2), dpi=100)
py.plot(tab_zf)
py.ylabel('Amplituda')
py.title('FSK')
py.show()

zf1fft=sc.fft(tab_zf)
(zad_11zf, zad_11zf_log)=widmo(zf1fft)

py.semilogx(zad_11zf)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji zf)')
py.show()


py.figure(figsize=(6, 2), dpi=100)
py.plot(tab_zp)
py.ylabel('Amplituda')
py.title('PSK')
py.show()

zp1fft=sc.fft(tab_zp)
(zad_11zp, zad_11zp_log)=widmo(zp1fft)

py.semilogx(zad_11zp)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji zp)')
py.show()

py.plot(zad_11za)
(W_zaa,fmin1,fmax1)=szerokosc_pasma(zad_11za)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji za) Szerokosć pasma: %i '%W_zaa)


print('Szerokosć pasma za)',W_zaa)    
        
rysowanie(fmin1,fmax1,dB)
    
py.show()


py.plot(zad_11zf)
(W_zf,fmin2,fmax2)=szerokosc_pasma(zad_11zf)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji zf) Szerokosć pasma: %i '%W_zf)


print('Szerokosć pasma zf)',W_zf)    
        
rysowanie(fmin2,fmax2,dB)
        
py.show() 


py.plot(zad_11zp)
(W_zp,fmin3,fmax3)=szerokosc_pasma(zad_11zp)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji zp) Szerokosć pasma: %i '%W_zp)


print('Szerokosć pasma zp)',W_zp)    
        
rysowanie(fmin3,fmax3,dB)
        
py.show()   





"""
Created on Thu Dec  6 14:18:21 2018
galaga
@author: Paweł

Temat:laboratorium
"""

