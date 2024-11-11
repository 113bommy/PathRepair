n,k=map(int,input().split())
a=[]
for i in range(1,10**3):
    
    if n%i==0:
        x=k*n/i+i
        if (x//k)*(x%k)==n:
            a.append(x)
print(min(a))
