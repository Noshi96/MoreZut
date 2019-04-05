import numpy as np
import matplotlib.pyplot as plot
import matplotlib.image as image
import copy
#from pylab import *

plot.figure(figsize=(12, 8), dpi=100)

obraz=image.imread('dobry.png')
obraz=obraz[:,:,1]
m=obraz.shape[0]
n=obraz.shape[1]


def jasnosc(obraz):
    j=np.sum((obraz)/(m*n))
    return j
    
    
def kontrast(obraz):
    k=np.power(np.sum((np.power((obraz-jasnosc(obraz)),2))/(m*n)),0.5)
    return k

#print("jasnosc")
#print(jasnosc(obraz))
#print("kontrast")
#print(kontrast(obraz))

obraz2=copy.copy(obraz)
obraz3=copy.copy(obraz)
obraz4=copy.copy(obraz)
obraz5=copy.copy(obraz)

size = 10
#x = range(1,size)


jastab1 = np.zeros(size)
jastab2 = np.zeros(size)
jastab3 = np.zeros(size)
jastab4 = np.zeros(size)
konttab1 = np.zeros(size)
konttab2 = np.zeros(size)
konttab3 = np.zeros(size)
konttab4 = np.zeros(size)

for i in range(1, size):
   obraz2 = obraz+(i/100)
   jastab1[i]=jasnosc(obraz2)
   konttab1[i]=kontrast(obraz2)
	
   obraz3 = obraz*(i/10)
   jastab2[i]=jasnosc(obraz3)
   konttab2[i]=kontrast(obraz3)
	
   obraz4 = np.power(obraz,i)
   jastab3[i]=jasnosc(obraz4)
   konttab3[i]=kontrast(obraz4)
  
   obraz5 = np.sqrt(obraz5)
   jastab4[i]=jasnosc(obraz5)
   konttab4[i]=kontrast(obraz5)
   

plot.subplot(531)
plot.grid()
plot.title("Jasnosc dodawanie(1)")
print("Wartosci jasnosc (1)")
print(jastab1)
print("________________________________________________________")
plot.plot(jastab1)

plot.subplot(532)
plot.grid()
plot.title("Kontrast dodawanie(1)")
print("Wartosci kontrast (1)")
print(konttab1)
print("________________________________________________________")
plot.plot(konttab1)

plot.subplot(533)
plot.grid()
plot.title("Jasnosc mnozenie(2)")
print("Wartosci jasnosc (2)")
print(jastab2)
print("________________________________________________________")
plot.plot(jastab2)

plot.subplot(534)
plot.grid()
plot.title("Kontrast mnozenie(2)")
print("Wartosci kontrast (2)")
print(konttab2)
print("________________________________________________________")
plot.plot(konttab2)

plot.subplot(535)
plot.grid()
plot.title("Jasnosc potegowanie(3)")
print("Wartosci jasnosc (3)")
print(jastab3)
print("________________________________________________________")
plot.plot(jastab3)

plot.subplot(536)
plot.grid()
plot.title("Kontrast potegowanie(3)")
print("Wartosci kontrast (3)")
print(konttab3)
print("________________________________________________________")
plot.plot(konttab3)

plot.subplot(537)
plot.grid()
plot.title("Jasnosc pierwiastkowanie(4)")
print("Wartosci jasnosc (4)")
print(jastab4)
print("________________________________________________________")
plot.plot(jastab4)

plot.subplot(538)
plot.grid()
plot.title("Kontrast pierwiastkowanie(4)")
print("Wartosci kontrast (4)")
print(konttab4)
print("________________________________________________________")
plot.plot(konttab4)

plot.subplot(539)
plot.title("(1)")
plot.imshow(obraz2,cmap = 'gray')

plot.subplot(5,3,10)
plot.title("(2)")
plot.imshow(obraz3,cmap = 'gray')

plot.subplot(5,3,11)
plot.title("(3)")
plot.imshow(obraz4,cmap = 'gray')

plot.subplot(5,3,12)
plot.title("(4)")
plot.imshow(obraz5,cmap = 'gray')

plot.subplot(5,3,13)
plot.title("(Orginał)")
plot.imshow(obraz,cmap = 'gray')


plot.tight_layout()
plot.show()

