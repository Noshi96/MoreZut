import numpy as np
import matplotlib.pyplot as plot
import matplotlib.image as image
import copy

plot.figure(figsize=(8, 4),dpi=100);

obraz=image.imread('litery_1.png');
obraz=obraz[:,:,0];

obraz=obraz[:,:,1];
m=obraz.shape[0];
n=obraz.shape[1];

maska=np.array([[1,1,1],[1,4,1],[1,1,1]])


maska5=np.array([[-3,-3,5],[-3,0,5],[-3,-3,5]]);
maska2=np.array([[-3,5,5],[-3,0,5],[-3,-3,-3]]);
maska3=np.array([[5,5,5],[-3,0,-3],[-3,-3,-3]]);
maska4=np.array([[5,5,-3],[5,0,-3],[-3,-3,-3]]);


obraz=(obraz*255).astype(int);
def filtr(obraz, maska):
    H=[];
    H1=[];
    suma=0;
    N=0;
    print(m);
    print(n);
    obraz2=obraz;
    for i in range(0,m):
        for j in range(0,n):
            H.append(0);

    #for i in range(o,m):
        #for j in range(0,n):
           # H1[maska[i],[j]]=

    
    N=np.sum(maska);
    
    for i in range (0,m):
        for j in range (0,n):
            for x in range (0,3):
                for y in range(0,3):
                    obraz2[i][j]]=(np.sum(np.sum(maska[x][y]*obraz[i+x][j+y])))/N;
                    #maska[x][y]*obraz[i][j];
       
        
    print(H);
    print(suma);
    print(obraz);
    plot.imshow(obraz,cmap = 'gray');
    plot.tight_layout();
    plot.show();
    
print("dziala");
filtr(obraz,maska);






