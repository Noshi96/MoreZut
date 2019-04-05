
"""
Obraz krawedzie Można gotowcem trzeba pobrać krawędzie

Wykryć kółko

Wykonać przeszukiwanie

pkt w obrazie to są punkty na potencialnym okręgu
wzór x=a+Rcos(q)
y=b+Rsin(tetz)


Macierz akumulator dla promienia r=10

rysujemy kółko o promieniu R

Funkcja tranformatem Hafa
przeliczać stopnie na radiany

iterujemy r=11,12
sprawdzamu duza ilosc promieni
R-min(m,n)/2
Przyjąć minimalny promień

Korzystać z pbrazka ze strony

Można iterować co 2 np

maxima wskazuja czy jest okrąg

Sprawdzamy wartoci a nie wstawiamy

obwód koła dla 12 cos kolo 62 ale u nas beda wyniki

liczyć sumę w okienku

Współczynnik np 75% sie przetnie to zakładamy ze juz jest koło


LISTA Srodki i promienie

Znaleźdź wszystkie okręgi

"""



import numpy as np
import matplotlib.pyplot as plot
import matplotlib.image as image


plot.figure(figsize=(10, 6), dpi=100)

obraz=image.imread('KOLKA_DO_ht.png')
obraz=obraz[:,:,0]

m=obraz.shape[0]
n=obraz.shape[1]

akumulator=[[m],[n]]

stop=np.pi/180

R=0
kat=10

def radian(kat):
    kat=kat*stop
    return kat

x=R*np.sin(radian(10)) 
y=R*np.cos(radian(10))


#poProgowaniu = (przedProgowaniem >= próg).astype('float64')

#w, k = np.where(acc >= próg)


def splot(obraz,maska):
    obraz2=obraz.copy();
    liczba_n=0;  #N2
    maska_m=maska.shape[0]; #MM
    maska_n=maska.shape[1];
    
    for i in range(0,maska_m):
        for j in range(0,maska_n):
             liczba_n+=maska[i,j]
    if liczba_n==0:
        liczba_n=1;
    
    for i in range (0,m-(maska_m-1)):    #odejmuje zeby nie wyjsc po za macierz
        for j in range (0,n-(maska_m-1)):
            suma=0.0;
            for k in range(0,maska_m):
                for l in range(0,maska_n):
                    suma+=obraz[i+k][j+l]*maska[k,l]; #wartosc z obrazka razy maska nie modyfikuje pixeli w rogach
            
            s=suma/liczba_n;      #wkladamw srodkowy element obrazka
            #print(s)
            obraz2[i+1][j+1]=s;
    
    
    
    
    return obraz2;

plot.imshow(obraz,cmap='gray')
plot.show();



maska=np.array([[-3,-3,5],[-3,0,5],[-3,-3,5]])
kir=np.power(splot(obraz,maska),2)
maska=np.array([[-3,5,5],[-3,0,5],[-3,-3,-3]])
kir+=np.power(splot(obraz,maska),2)
maska=np.array([[5,5,5],[-3,0,-3],[-3,-3,-3]])
kir+=np.power(splot(obraz,maska),2)
maska=np.array([[5,5,-3],[5,0,-3],[-3,-3,-3]])
kir+=np.power(splot(obraz,maska),2)
maska=np.array([[5,-3,-3],[5,0,-3],[5,-3,-3]])
kir+=np.power(splot(obraz,maska),2)
maska=np.array([[-3,-3,-3],[5,0,-3],[5,5,-3]])
kir+=np.power(splot(obraz,maska),2)
maska=np.array([[-3,-3,-3],[-3,0,-3],[5,5,5]])
kir+=np.power(splot(obraz,maska),2)
maska=np.array([[-3,-3,-3],[-3,0,5],[-3,5,5]])
kir+=np.power(splot(obraz,maska),2)
kir=np.sqrt(kir);
plot.figure(figsize=(10, 6), dpi=100)
print("Filtr Kirscha")






plot.imshow(kir,cmap='gray');
plot.show();




"""
Pierwszy czerwca oddajemy !wszystko już zrobione, 15 jest poprawka



progowanie maximum
dla wartosci wiekszych od zera rysować kółka



"""




