import numpy as np
import matplotlib.pyplot as plot
import matplotlib.image as image
import copy
#from pylab import *

plot.figure(figsize=(10, 6), dpi=100)

obraz=image.imread('kierowca.png')
obraz=obraz[:,:,1]
m=obraz.shape[0]
n=obraz.shape[1]

mini=0
maxi=255
punkty=16

x=np.linspace(mini,maxi,punkty)

obraz=(obraz*255).astype(int);
  




def histogram (obraz,ile):
    H=[];
    rozmiar=[];
    przedzial=[];
    rozmiar_przedzialu=[];
    
    for i in range(0,256):
        H.append(0);
        rozmiar.append(i); 
        
    for i in range (0,m):
        for j in range (0,n):
            H[obraz[i][j]] +=1;
    #Hp2=copy.copy(H)/np.sum(H);
    #print(H);
    #print(Hp);
    
    for i in range(0,ile):
        przedzial.append(0);
        rozmiar_przedzialu.append(i);
        
    for i in range (0,256):
        x= int(i%ile);
        #print(x);
        przedzial[x]+=H[i];
    #Hp=copy.copy(przedzial)/np.sum(przedzial);
    #plot.subplot(121);
    #plot.plot(rozmiar,H,'black');
    plot.subplot(122);
    plot.plot(rozmiar_przedzialu,przedzial,'b');
    return H;      



def Liniowe(obraz):
    min_ = np.min(obraz);
    max_ = np.max(obraz);
    H = np.zeros((m,n))
    for i in range(0,m):
        for j in range(0,n):
            H[i,j] = ((obraz[i,j] - min_)/(max_-min_));
    H=(H*255).astype(int);
    return H;


def lin(obraz):
    obraz2= Liniowe(obraz);
    histogram(obraz2,255);
    plot.subplot(121);
    plot.title("Rozciaganie liniowe");
    plot.imshow(obraz2,cmap = 'gray');
    plot.tight_layout();
    plot.show();
    
def pods(obraz):
    obraz2=obraz;
    obraz2=obraz2.astype(int);
    histogram(obraz2,255);
    plot.subplot(121);
    plot.title("Podstawa");
    plot.imshow(obraz2,cmap = 'gray');
    plot.tight_layout();
    plot.show();
    

def potegowanie(obraz):
    #obraz2=0.01*np.power(obraz,2);
    obraz2=np.power(obraz,2);
    obraz2[obraz2>255]=255;
    obraz2=obraz2.astype(int);
    
    histogram(obraz2,255);
    plot.subplot(121);
    plot.title("Potega");
    plot.imshow(obraz2,cmap = 'gray');
    plot.tight_layout();
    plot.show();
    
def pierwiastkowanie(obraz):
    obraz2=2*np.power(obraz,1/2);
    #obraz2=np.power(obraz,1/2);
    #obraz2[obraz2>255]=255;
    obraz2=obraz2.astype(int);
    
    lin(obraz2)
    
    histogram(obraz2,255);
    plot.subplot(121);
    plot.title("Pierwiastek");
    plot.imshow(obraz2,cmap = 'gray');
    plot.tight_layout();
    plot.show();
    
def logarytm(obraz):
    obraz2=0.4*np.log(obraz)+1;
    obraz2[obraz2>255]=255;
    obraz2[obraz2<0]=0;
    obraz2=obraz2.astype(int);
    
    histogram(obraz2,255);
    plot.subplot(121);
    plot.title("Logarytm");
    plot.imshow(obraz2,cmap = 'gray');
    plot.tight_layout();
    plot.show();
    
def wykladnicza(obraz):
    #obraz2=0.000000000000000000000000000000001*np.power(np.e, obraz);
    obraz2=np.power(np.e, obraz);
    obraz2[obraz2>255]=255;
    obraz2[obraz2<0]=0;
    obraz2=obraz2.astype(int);
    
    histogram(obraz2,255);
    plot.subplot(121);
    plot.title("Wykladnicza");
    plot.imshow(obraz2,cmap = 'gray');
    plot.tight_layout();
    plot.show();
    
#obraz2=Liniowe(obraz);
    
    
pods(obraz); 
lin(obraz);    
potegowanie(obraz);
pierwiastkowanie(obraz);
logarytm(obraz);
wykladnicza(obraz);






#obraz3=np.power(obraz,2);
#print(obraz3);
#pierwiastkowanie(obraz);

#histogram(obraz3,250);


#filtracja splotowa
#funkcja filtracji
#filtracja laplaca
#filtracja robertsa
#filtracja sobela
#filtracja premita
#4 filtracje
#zintegrować 4 obrazki ktore pokazuja krawedzie?
#kwadratować macierz wynikowa i pierwiastuje wynik 1.z 2 metod

#wymieniac maski?
#zmodyfikować obrazy zeby miały podobny charakter

#kryteria:
 #   odpornosc na szum eksponuje tylko krawedzie nie ma kaszy(cecha filtra)
 #   Dokładnosc wykrywania krawwedzi czy filtry przesuwaja krawedzie
 #   Jednoznacznosć który z filtrow daje krawedzie grube pikselowe a ktore cienkie pikselowe
    
    



