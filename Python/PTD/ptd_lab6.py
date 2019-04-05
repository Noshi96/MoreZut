# -*- coding: utf-8 -*-
"""
Created on Thu Jan 17 15:09:55 2019

@author: Paweł
"""
import numpy as np

from operator import xor

def haminga(bity):
    
    
    S=0
    wyjscie=[0,0,0,0,0,0,0]
    
    
    if(len(bity)==4):
        print('Sygnał wejsciowy:      ',bity)

        wyjscie[0]=bity[0]
        wyjscie[1]=bity[1]
        wyjscie[2]=bity[2]
        wyjscie[4]=bity[3]
        
        policzonyx1=xor(xor(wyjscie[4],wyjscie[2]),wyjscie[0])
        policzonyx2=xor(xor(wyjscie[4],wyjscie[1]),wyjscie[0])
        policzonyx4=xor(xor(wyjscie[2],wyjscie[1]),wyjscie[0])
        
        wyjscie[3]=policzonyx4
        wyjscie[5]=policzonyx2
        wyjscie[6]=policzonyx1
        print('Zakodowany sygnał:     ',wyjscie)        
    elif(len(bity)==7):
        wyjscie=bity
        print('Sygnał do detekcji:    ',wyjscie)
         
        
    odczytanyx1=wyjscie[6]
    odczytanyx2=wyjscie[5]
    odczytanyx4=wyjscie[3]
    
    policzonyx1=xor(xor(wyjscie[4],wyjscie[2]),wyjscie[0])
    policzonyx2=xor(xor(wyjscie[4],wyjscie[1]),wyjscie[0])
    policzonyx4=xor(xor(wyjscie[2],wyjscie[1]),wyjscie[0])
    
    wynikx1=xor(odczytanyx1,policzonyx1)
    wynikx2=xor(odczytanyx2,policzonyx2)
    wynikx4=xor(odczytanyx4,policzonyx4)
    
    S=1*wynikx1+np.power(2,1)*wynikx2+np.power(2,2)*wynikx4
    
    if(S!=0):
        print()
        print('Przekłamany bit na pozycji: ',S)
        print()
        wyjscie.reverse()
        if(wyjscie[S-1]==1):
            wyjscie[S-1]=0
        else:
            wyjscie[S-1]=1
        wyjscie.reverse()
        print('Korekcja sygnału:      ',wyjscie)
    elif(len(bity)!=4 and S==0):
        print('Sygnał jest poprawny')
    return wyjscie

bity=[1,1,0,0]
(nowe)=haminga(bity)
tab=[1, 1, 0, 0, 0, 0, 0]
(pozamianie)=haminga(tab)




    
    