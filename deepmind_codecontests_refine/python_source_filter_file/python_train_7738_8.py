def isPrime(x):
    i=int(3)
    while i*i<=x:
        if x%i==0:
            return False
        i+=1
    return True

l=[]
for i in range(3,1009,2):
    if isPrime(i):
        l.append(i)
       # print(i)
n,k=map(int,input().split())
for i in range(len(l)-1):
    if l[i]+l[i+1]+1 in l:
        k-=1
    if l[i]+l[i+1]+1>n or k==0:
        break
print("N0" if k else "YES")
        
