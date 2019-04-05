import pylab as py
import numpy as np
import scipy as sc


 
#wybrac czestotliwosc t i fs samodzielnie 
#sin 100hz z zasada probkowania 2x

#Parametry samemu dobieramy

#xn=An sin(2pi fn+fin)

#m(t)=Am sin(2pi*fm*t)

#xn(t)=[kam*m(t)+1] * sin(2pi Fn + fiN)

def szerokosc_pasma(lista):
    dB=-3
    tablica_minmax=[]
    for i in range (len(lista)):
        if lista[i]>dB:
            tablica_minmax.append(i)
        
    ffmin=tablica_minmax[0]
    ffmax=tablica_minmax[len(tablica_minmax)-1]
            
    WW=ffmax-ffmin
    return (WW,ffmin,ffmax)

def widmo(dft_tab):
    tab_log=[]
    Mprim=0
    
    M=0
    tab_wynik2=[]
    N=len(dft_tab)
    
    for k in range(0,int(N/2)):
        M=np.sqrt(np.power(dft_tab[k].real,2)+np.power(dft_tab[k].imag,2))
        tab_wynik2.append(M)
        
        Mprim=10*np.log10(M)
        tab_log.append(Mprim)
            
    
    return (tab_wynik2, tab_log)


"""
 T=1
    T=1
    Am=1
    fm=5
    fn=100
    Fs=2*fn
    dt = 1.0/Fs
"""

def sin(ka,kp):
    T=1
    Am=1
    fm=2
    fn=25
    Fs=2000
    dt = 1.0/Fs
    
    t = np.arange(0,T,dt)
    
    m = Am*np.sin(2*np.pi*fm*t)
    za = (ka*m+1)*np.cos(np.pi*2*fn*t)
    zp = np.cos(np.pi*2*fn*t+kp*m)
    #print(m)
    #print(za)
    #print(zp)
    return (m,t,za,zp)
	
dB=-3

(m1,t,za1,zp1) = sin(ka=0.7,kp=1.3)
(m2,t,za2,zp2) = sin(ka=8,kp=2.27)
(m3,t,za3,zp3) = sin(ka=40,kp=60)

py.plot(m1)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Sygnał informacyjny a)')
py.show()

py.plot(za1)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Modulacja amplitudy a)')
py.show()

za1fft=sc.fft(za1)
zp1fft=sc.fft(zp1)

(zad_11za, zad_11za_log)=widmo(za1fft)
(zad_11zp, zad_11zp_log)=widmo(zp1fft)

#py.loglog(zad_11za_log,basex=10)
#py.plot(zad_11za)
py.semilogx(zad_11za)

py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji amplitudy a)')
  
py.show()


py.semilogx(zad_11za_log)

py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('[skala decybelowa] Widmo amplitudowe modulacji amplitudy a)')

(W_zaa,fmin1,fmax1)=szerokosc_pasma(zad_11za_log)
print('Szerokosć pasma za a)',W_zaa)    
    
xposition1 = [fmin1,fmax1]
for xc in xposition1:
    py.axvline(x=xc, color='r', linestyle='--')
    
    
yposition1 = [dB]
for yc in yposition1:
    py.axhline(y=yc, color='r', linestyle='--')    
    
py.show()   
    

#py.loglog(zad_11zp,basex=10)
#py.plot(zad_11zp)
py.semilogx(zad_11zp)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji kąta a)')
py.show()


py.semilogx(zad_11zp_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('[skala decybelowa] Widmo amplitudowe modulacji kąta a)')

(W_zpa,fmin2,fmax2)=szerokosc_pasma(zad_11zp_log)
print('Szerokosć pasma zp a)',W_zpa)
    
xposition2 = [fmin2,fmax2]
for xc in xposition2:
    py.axvline(x=xc, color='r', linestyle='--')
    
    
yposition2 = [dB]
for yc in yposition2:
    py.axhline(y=yc, color='r', linestyle='--')    
    
py.show()       
    

py.plot(m2)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Sygnał informacyjny b)')
py.show()

py.plot(za2)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Modulacja amplitudy b)')
py.show()

za1fft2=sc.fft(za2)
zp1fft2=sc.fft(zp2)

(zad_11za2, zad_11za2_log)=widmo(za1fft2)
(zad_11zp2, zad_11zp2_log)=widmo(zp1fft2)

#py.loglog(zad_11za2,basex=10)
#py.plot(zad_11za2)
py.semilogx(zad_11za2)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji amplitudy b)')
py.show()


py.semilogx(zad_11za2_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('[skala decybelowa] Widmo amplitudowe modulacji amplitudy b)')

(W_zab,fmin3,fmax3)=szerokosc_pasma(zad_11za2_log)
print('Szerokosć pasma za b)',W_zab)    
    
xposition3 = [fmin3,fmax3]
for xc in xposition3:
    py.axvline(x=xc, color='r', linestyle='--')
    
    
yposition3 = [dB]
for yc in yposition3:
    py.axhline(y=yc, color='r', linestyle='--')     
    
py.show()


#py.loglog(zad_11zp2,basex=10)
#py.plot(zad_11zp2)
py.semilogx(zad_11zp2)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji kąta b)')
py.show()



py.semilogx(zad_11zp2_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('[skala decybelowa] Widmo amplitudowe modulacji kąta b)')

(W_zpb,fmin4,fmax4)=szerokosc_pasma(zad_11zp2_log)
print('Szerokosć pasma zp b)',W_zpb)

xposition4 = [fmin4,fmax4]
for xc in xposition4:
    py.axvline(x=xc, color='r', linestyle='--')
    
    
yposition4 = [dB]
for yc in yposition4:
    py.axhline(y=yc, color='r', linestyle='--')     
    
py.show()

py.plot(m3)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Sygnał informacyjny c)')
py.show()

py.plot(za3)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Modulacja amplitudy c)')
py.show()

za1fft3=sc.fft(za3)
zp1fft3=sc.fft(zp3)

(zad_11za3, zad_11za3_log)=widmo(za1fft3)
(zad_11zp3, zad_11zp3_log)=widmo(zp1fft3)

#py.loglog(zad_11za3,basex=10)
#py.plot(zad_11za3)
py.semilogx(zad_11za3)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji amplitudy c)')
py.show()

py.semilogx(zad_11za3_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('[skala decybelowa] Widmo amplitudowe modulacji amplitudy c)')

(W_zac,fmin5,fmax5)=szerokosc_pasma(zad_11za3_log)
print('Szerokosć pasma za c)',W_zac)    
    
xposition5 = [fmin5,fmax5]
for xc in xposition5:
    py.axvline(x=xc, color='r', linestyle='--')
    
    
yposition5 = [dB]
for yc in yposition5:
    py.axhline(y=yc, color='r', linestyle='--')     
    
py.show()

#y.loglog(zad_11zp3,basex=10)
#py.plot(zad_11zp3)
py.semilogx(zad_11zp3)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('Widmo amplitudowe modulacji kąta c)')
py.show()



py.semilogx(zad_11zp3_log)
py.xlabel('Częstotliwosć [Hz]')
py.ylabel('Amplituda')
py.title('[skala decybelowa] Widmo amplitudowe modulacji kąta c)')

(W_zpc,fmin6,fmax6)=szerokosc_pasma(zad_11zp3_log)
print('Szerokosć pasma zp c)',W_zpc)
print(fmin6)
xposition6 = [fmin6,fmax6]
for xc in xposition6:
    py.axvline(x=xc, color='r', linestyle='--')
    
    
yposition6 = [dB]
for yc in yposition6:
    py.axhline(y=yc, color='r', linestyle='--')     
    
py.show()

#Laboratorium

"""
Lab3:
    
    Albo między zajęciami
    na 
"""