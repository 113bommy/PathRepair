def verif_nearlyprime(n):
    if verif_prime(n)==True :
        return False
    else : 
        l=list()
        l=[i for i in range(2,(n//2+1)) if n % i== 0]
        test=False
        j=0
        k=len(l)-1
        while  test==False and (j<=k) :
            if verif_prime(l[k])==True and verif_prime(l[j])==True :
                test=True
            else :
                j=j+1 
                k=k-1    
        return test 

def verif_prime(n):
    if n==1 :
        return True
    else :
        i=2
        test=True
        while (i<=n//2) and test:
            if n%i==0 :
                test=False 
            else :
                i=i+1            
        return test
t=int(input())
l=list()
for i in range(t):
    n=int(input())
    l.append(n)

l.sort()
for i in l:
    l1=[6,10,14] #sauf 6,10,14 vaut pour 36 40 44
    if i<=30 :
        print("no")
    else :
        r=i-30
        if (r in l1) == False :
            l1.append(r)
        else :
            j=l1[-1]+1
            k=1
            while verif_nearlyprime(j)==False:
              j=j+1
              k=k+1
            l1[-1]=j  
            l1.append(r-k) 
        print('yes')
        print(l1[0],l1[1],l1[2],l1[3])  