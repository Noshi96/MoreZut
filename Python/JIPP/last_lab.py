import numpy as np

def wprowadz_dane(dane):
    print('Podaj a:')
    a=input()
    dane.append(int(a))
    print('Podaj b:')
    b=input()
    dane.append(int(b))
    print('Podaj c:')
    c=input()
    dane.append(int(c))
    print('Podaj d:')
    d=input()
    dane.append(int(d))
    return dane
    

def formatuj_rownanie(dane):
   
    if (dane[0] > 0):
        print(dane[0],"xx",sep="",end="")
    elif (dane[0]<0):
        print(dane[0],"xx",sep="",end="")
    else:
        print("",sep="",end='')
    if (dane[1] > 0 and dane[0] != 0):
        print("+",dane[1],"x",sep="",end="")
    elif (dane[1] > 0 and dane[0] == 0):
        print(dane[1],"x",sep="",end="")
    elif (dane[1]<0):
        print(dane[1],"x",sep="",end="")
    elif (dane[1] == 0 and dane[0] != 0):
        print("",sep="",end="")
    else:
        print("",sep="",end="")
    if (dane[2] > 0):
        print("+",dane[2],sep="",end="")
    elif (dane[2]<0):
        print(dane[2],sep='',end='')
    else:
        print("",sep="",end="")
    if (dane[3] > 0 and dane[2] == 0 and dane[1] == 0 and dane[0] == 0):
        print(dane[3],"i=0",sep="",end="")
        print('')
    elif (dane[3] > 0):
        print("+",dane[3],"i=0",sep="",end="")
        print("")
    elif (dane[3]<0):
        print(dane[3],"i=0",sep="",end="")
        print("")
    else:
        print("=0",sep="",end="")
        print("")



def oblicz_delte(dane):
     delta = (dane[1]*dane[1]) - (4*dane[0]*dane[2]) -4j*dane[0]*dane[3]
     return delta
 
def oblicz_pdelte(delta):
    pdelta=np.sqrt(delta)
    return pdelta


def oblicz_rownanie(dane, wynik):
    
    if (dane[0]!=0 and dane[3]==0):
        wynik.append(oblicz_delte(dane))        #Wynik[0] delta
        
        #1.1 #wynik[1]=x1r wynik[2]=x2r wynik[3]=sumar wynik[4]=roznicar wynik[5]=iloczynr 
        
        if((np.real(wynik[0])) > 0):
            wynik.append(0.5*(-dane[1]-np.sqrt(np.real(wynik[0])))/dane[0])
            wynik.append(0.5*(-dane[1]+np.sqrt(np.real(wynik[0])))/dane[0])
            wynik.append(wynik[2]+wynik[3])
            wynik.append(wynik[2]-wynik[3])
            wynik.append(wynik[2]*wynik[3])
            if(np.real(wynik[2])!=0):
                wynik.append(np.real(wynik[1]/np.real(wynik[2])))   #iloraz
            else:
                x=0
                wynik.append(x)
            
            wynik.append((np.real(wynik[1])/np.real(wynik[2]))+0*1j)
        #1.2 wynik[2]=x1r
        if((np.real(wynik[0]))==0):
            wynik.append(-0.5*dane[1]/dane[0])
            wynik.append(wynik[1]*-1)   #przeciwny
            if(wynik[1]!=0):
                wynik.append(1/np.real(wynik[1]))            #odwrotny
            else:
                b=0
                wynik.append(b)
            
            
        #1.3 wynik[2]=x1r
        if(np.real(wynik[0])<0):
            wynik.append(0.5*(-dane[1]-np.sqrt(-np.real(wynik[0]))*1j)/dane[0])
            wynik.append(np.conj(wynik[1]))
            wynik.append(wynik[1]+wynik[2])
            wynik.append(wynik[1]-wynik[2])
            wynik.append(wynik[1]*wynik[2])
            wynik.append(  ( ((( np.real(wynik[1])*np.real(wynik[2])) + (np.imag(wynik[1]) *np.imag(wynik[2]) ))/(np.power(np.real(wynik[2]),2) + np.power(np.imag(wynik[2]),2) ) ) + (((np.real(wynik[2]) * np.imag(wynik[1])) - (np.real(wynik[1])*np.imag(wynik[2]) ) )/(   np.power(np.real(wynik[2]),2) + np.power(np.imag(wynik[2]),2) )     )*1j  )  )                                              
                
            
    #2.
    if (dane[0]==0 and dane[1]!=0 and dane[3]==0):
        wynik.append(-1.0*dane[2]/dane[1])
        wynik.append(-1*np.conj(wynik[0])) #przeciwny
        if(np.real(wynik[0])!=0):
            wynik.append(1/np.real(wynik[0]))
        else:
            wynik.append(0)
        
    #5
    if (dane[0]==0 and dane[1]!=0 and dane[3]!=0):
        wynik.append(-dane[2]/dane[1]-dane[3]*1j/dane[1])
        wynik.append(wynik[0]*-1)  #przeciwny
        wynik.append(( (np.real(wynik[0]))/(np.power(np.real(wynik[0]),2) + np.power(np.imag(wynik[0]),2) ) ) +((-np.imag(wynik[0]))/(np.power(np.real(wynik[0]),2) +np.power(np.imag(wynik[0]),2) )  )*1j )
        
        
    #6
    if (dane[0]!=0 and dane[3]!=0):
        wynik.append(oblicz_delte(dane))
        wynik.append((-dane[1]-np.real(oblicz_pdelte(wynik[0]))-((dane[1]-np.imag(oblicz_pdelte(wynik[0])))*1j))/(2*dane[0]))
        wynik.append((-dane[1]-np.real(oblicz_pdelte(wynik[0]))-((dane[1]+np.imag(oblicz_pdelte(wynik[0])))*1j))/(2*dane[0]))
        wynik.append((-dane[1]+np.real(oblicz_pdelte(wynik[0]))-((dane[1]+np.imag(oblicz_pdelte(wynik[0])))*1j))/(2*dane[0]))
        wynik.append((-dane[1]+np.real(oblicz_pdelte(wynik[0]))-((dane[1]-np.imag(oblicz_pdelte(wynik[0])))*1j))/(2*dane[0]))
        wynik.append(wynik[1]+wynik[2]+wynik[3]+wynik[4])
        wynik.append(wynik[1]-wynik[2]-wynik[3]-wynik[4])
        wynik.append(wynik[1]*wynik[2]*wynik[3]*wynik[4])
        wynik.append(wynik[1]/wynik[2]/wynik[3]/wynik[4]) #iloraz

    return wynik

def wyswietl_wynik (dane, wynik):
    if (dane[0]!=0 and dane[3]==0):
        print("delta=",wynik[0])
        
        
         #1.1
        if(np.real(oblicz_delte(dane))>0):
           print("x1=",wynik[1])
           print("x2=",wynik[2])
           print("s=",wynik[3])
           print("r=",wynik[4])
           print("il=",wynik[5])
           print("iloraz",wynik[6])#
           
           #1.2
        if(np.real(oblicz_delte(dane))<0):
           print("x1=",wynik[1])
           print("x2=",wynik[2])
           print("s=",wynik[3])
           print("r=",wynik[4])
           print("il=",wynik[5])
           print("iloraz",wynik[6])#
           
        #1.3   
        if(np.real(oblicz_delte(dane))==0):
            print("x1=",wynik[1])
            print("Przeciwny= ",wynik[2])
            print("Odwrotny= ",wynik[3])
            
    #2  
    if (dane[0]==0 and dane[1]!=0 and dane[3]==0):
        print("x1=",wynik[0])
        print("przeciwny ",wynik[1])
        print("odwrotny",wynik[2])

    #3
    if (dane[0]==0 and dane[1]==0 and (dane[2]!=0 or dane[3]!=0)):
        print("Rownanie jest sprzeczne")
    
    #4
    if (dane[0]==0 and dane[1]==0 and dane[2]==0 and dane[3]==0):
        print("Rownanie jest tozsamosciowe");

    #5
    if (dane[0]==0 and dane[1]!=0 and dane[3]!=0):
        print("x1=",wynik[0])
        print("Przeciwny= ",wynik[1])
        print("Odwrotny= ",wynik[2])

    #6
    if (dane[0]!=0 and dane[3]!=0):
        print("delta=",wynik[0])
        print("x1=",wynik[1])
        print("x2=",wynik[2])
        print("x3=",wynik[3])
        print("x4=",wynik[4])
        print("s=",wynik[5])
        print("r=",wynik[6])
        print("il=",wynik[7])
        print("iloraz=",wynik[8])

    return
                        
dane=[]
wynik=[]

dane=wprowadz_dane(dane)
formatuj_rownanie(dane)
wynik=oblicz_rownanie(dane,wynik)
wyswietl_wynik(dane,wynik)


dane.clear()
wynik.clear()

