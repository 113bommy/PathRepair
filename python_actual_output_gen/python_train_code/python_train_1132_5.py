t=int(input())
for _ in range(t):
    n=int(input())
    k=len(str(n))
    k1=""
    for i in range(k):
        k1+="1"
    c=9*(k-1)
    
    k1=int(k1)
    k2=k1
    while((k1)<n):
        (k1)=(k1)+(k2)
        c+=1
        
    print(c)