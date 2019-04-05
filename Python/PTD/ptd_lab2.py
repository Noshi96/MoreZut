import pylab as py
import numpy as np
import scipy as sc
import time

 
def sin(f = 1, T = 1, Fs = 128, phi =np.pi ):
	dt = 1.0/Fs
	t = np.arange(0,T,dt)
	s = np.cos(2*np.pi*f*t + phi)*pow((t/2),0.12)
	return (s,t)
 
(s,t) = sin(f=100,Fs=8000)

def dft(lista):
    tab_wynik = []
    N = len(lista)
    for k in range(N):
        wynik = 0
        for n in range(N):
            wynik =wynik + lista[n]*(np.power(np.e,((-2j*np.pi*k*n)/N)))
        tab_wynik.append(wynik)
    return tab_wynik


def sin_2(f = 1, T = 1, Fs = 128, phi =np.pi ):
    dt=1.0/Fs
    t=np.arange(0,T,dt)
    s=np.cos(2*np.pi*f*t+phi)*pow((t/2),0.12)
    
    y=(np.power(t,2)/(t+1))
    
    
    #ZAD 2 a)
    
    z=((t/3)*np.abs((0.1*s)-((0.65/(t+1))*y)))
    
    #ZAD 2 b)
    
    v=3*np.power(s,7)*np.sqrt(np.abs(y))
    
    return(v,t,z)
 
(v,t1,z) = sin_2(f=100,Fs=8000)




def widmo(dft_tab, Fs):
    tab_log=[]
    Mprim=0
    Fk=[]
    M=0
    tab_wynik2=[]
    N=len(dft_tab)
    for k in range(0,int(N/2)):
        M=np.sqrt(np.power(dft_tab[k].real,2)+np.power(dft_tab[k].imag,2))
        tab_wynik2.append(M)
        
        Mprim=10*np.log10(M)
        tab_log.append(Mprim)
        
        Fk.append(k*(Fs/N))
    
    return (tab_wynik2, tab_log, Fk)




def zadanie3():
    f = 1
    T = 1 
    Fs = 4000

    dt=1.0/Fs

    t1=np.arange(0,0.4,dt)
    t2=np.arange(0.4,0.6,dt)
    t3=np.arange(0.6,0.8,dt)
    t4=np.arange(0.8,1,dt)

    u1=np.power(0.8,t1)-1
    u2=-1.8*t2*np.cos(16*np.pi*(t2/Fs)+np.pi)
    u3=0.72*t3
    u4=(0.29*np.power(t4,8)*np.sin(31*np.pi*(t4/Fs)))+0.55

    u5=[]

    u5.extend(u1)
    u5.extend(u2)
    u5.extend(u3)
    u5.extend(u4)
    
    return u5



def zadanie4():
    Fs=10000
    T=1
    dt=T/Fs
    t=np.arange(0,T,dt)


#ZAD 4 a)

    H1=2

#ZAD 4 b)

    H2=20

    #ZAD 4 c)

    H3=200
    g=0
    g2=0
    g3=0
    for p in range(1,H1):
        g=g+((np.power(-1,p)/p)*((np.cos(p*np.pi*2*t))-1)*(np.sin(p*np.pi*t)))
    g=g*(2/np.pi)
    
    for p in range(1,H2):
        g2=g2+((np.power(-1,p)/p)*((np.cos(p*np.pi*2*t))-1)*(np.sin(p*np.pi*t)))
    g2=g2*(2/np.pi)
    
    for p in range(1,H3):
        g3=g3+((np.power(-1,p)/p)*((np.cos(p*np.pi*2*t))-1)*(np.sin(p*np.pi*t)))
    g3=g3*(2/np.pi)

    
    return (g,g2,g3,t)



#Zad 1 P1

start11fft = time.clock()    
sc.fft(s)
end11fft = time.clock()

czas11fft=(end11fft-start11fft)*1000

print('Zad1_1_FFT') 
print(czas11fft)

print()

start11dft = time.clock() 
dft_zad_11=dft(s)
end11dft = time.clock()

czas11dft=(end11dft-start11dft)

print('Zad1_1_DFT') 
print(czas11dft)


(zad_11, zad_11_log, Fk1)=widmo(dft_zad_11, Fs=8000)




py.plot(Fk1,zad_11_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 1 Przykład 1')

py.tight_layout();
py.show()



py.loglog(Fk1,zad_11_log, basex=10)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 1 Przykład 1 LOG')

py.tight_layout();
py.show()


start21fft = time.clock()    
sc.fft(z)
end21fft = time.clock()

czas21fft=(end21fft-start21fft)*1000

print('Zad2_1_FFT') 
print(czas21fft)

print()


start21dft = time.clock()
dft_zad_21=dft(z)
end21dft = time.clock()

czas21dft=(end21dft-start21dft)

print('Zad2_1_DFT') 
print(czas21dft)



(zad_21, zad_21_log, Fk2)=widmo(dft_zad_21,Fs=8000)


py.plot(Fk2,zad_21_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 2 Przykład 1')

py.tight_layout();
py.show()


py.loglog(Fk2,zad_21_log, basex=10)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 2 Przykład 1 LOG')

py.tight_layout();
py.show()




start22fft = time.clock()    
sc.fft(v)
end22fft = time.clock()

czas22fft=(end22fft-start22fft)*1000

print('Zad2_2_FFT') 
print(czas22fft)

print()

start22dft = time.clock()
dft_zad_22=dft(v)
end22dft = time.clock()

czas22dft=(end22dft-start22dft)

print('Zad2_2_DFT') 
print(czas22dft)


(zad_22, zad_22_log, Fk22)=widmo(dft_zad_22,Fs=8000)


py.plot(Fk22, zad_22_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 2 Przykład 2')

py.tight_layout();
py.show()

py.loglog(Fk22, zad_22_log,basex=10)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 2 Przykład 2 LOG')

py.tight_layout();
py.show()

(u)=zadanie3()




start31fft = time.clock()    
sc.fft(u)
end31fft = time.clock()

czas31fft=(end31fft-start31fft)*1000

print('Zad3_1_FFT') 
print(czas31fft)

print()


start31dft = time.clock()
dft_zad_31=dft(u)
end31dft = time.clock()

czas31dft=(end31dft-start31dft)

print('Zad3_1_DFT') 
print(czas31dft)




(zad_31, zad_31_log, Fk31)=widmo(dft_zad_31,Fs=4000)


py.plot(Fk31, zad_31_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 3')

py.tight_layout();
py.show()

py.loglog(Fk31, zad_31_log,basex=10)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 3 LOG')

py.tight_layout();
py.show()



(g,g2,g3,t)=zadanie4()



start41fft = time.clock()    
dft_zad_41=sc.fft(g)
end41fft = time.clock()

czas41fft=(end41fft-start41fft)*1000

print('Zad4_1_FFT') 
print(czas41fft)

print()


start41dft = time.clock()
dft(g)
end41dft = time.clock()

czas41dft=(end41dft-start41dft)

print('Zad4_1_DFT') 
print(czas41dft)

print()


(zad_41, zad_41_log, Fk41)=widmo(dft_zad_41,Fs=10000)


start42fft = time.clock()    
dft_zad_42=sc.fft(g2)
end42fft = time.clock()

czas42fft=(end42fft-start42fft)*1000

print('Zad4_2_FFT') 
print(czas42fft)

print()


start42dft = time.clock()
dft(g2)
end42dft = time.clock()

czas42dft=(end42dft-start42dft)

print('Zad4_2_DFT') 
print(czas42dft)

print()

(zad_42, zad_42_log, Fk42)=widmo(dft_zad_42,Fs=10000)


start43fft = time.clock()    
dft_zad_43=sc.fft(g3)
end43fft = time.clock()

czas43fft=(end43fft-start43fft)*1000

print('Zad4_3_FFT') 
print(czas43fft)

print()


start43dft = time.clock()
dft(g3)
end43dft = time.clock()

czas43dft=(end43dft-start43dft)

print('Zad4_3_DFT') 
print(czas43dft)


(zad_43, zad_43_log, Fk43)=widmo(dft_zad_43,Fs=10000)


py.plot(Fk41, zad_41_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 4 Przykład 1')

py.tight_layout();
py.show()

py.loglog(Fk41, zad_41_log,basex=10)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 4 Przykład 1 LOG')

py.tight_layout();
py.show()


py.plot(Fk42, zad_42_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 4 Przykład 2')

py.tight_layout();
py.show()

py.loglog(Fk42, zad_42_log,basex=10)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 4 Przykład 2 LOG')

py.tight_layout();
py.show()


py.plot(Fk43, zad_43_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 4 Przykład 3')

py.tight_layout();
py.show()

py.loglog(Fk43, zad_43_log,basex=10)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda widma')
py.title('Zad 4 Przykład 3 LOG')

py.tight_layout();
py.show()

#ZAD2
"""
 
 Funkcja z pierwszego (DFT) obliczyć widma amplitudowe
 Dla sygnałów z lab 1 obliczyć widma (podać na wejciu dft)
 log i liniowa =te same wykresy z róznymi skalami
 
 ZAD3
 uruchom DFT z pomiarem czasu //cykle
 //mała różnica
 Zamiast DFT FFT
 FFT tak samo interpretujemy  {FFTW biblioteka stosowana można się zapoznać z API}
 Wyniki w tabeli screen z exela
 Na NEXT:
"""
        
        
#Konsultacje pon 12-14
