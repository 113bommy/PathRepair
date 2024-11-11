import math

l=[]
for i in range(30):
    a=pow(2,i)
    if a<=pow(10,9)+1:
        l.append(a)    
        

zz=int(input())
for aa in range(zz):
    n=int(input())
    som =(n * (n+1)) //2
    s=0
    for j in l:
        if (j <= n):
            s=s+j
    
    print(int(som) - 2*int(s))
