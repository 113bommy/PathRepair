def ii(): return int(input())
def fi(): return float(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi())
 
def su(n):
    s=0 
    while(n!=0):
        a=n%10 
        s+=a 
        n//=10 
    return s
 
n=ii()
a=li()
c=1
k=[]
for i in range(n-1):
    if a[i]==a[i+1]:
        c+=1 
    else:
        k.append(c)
        c=1 
k.append(c)
print(k)
ans=0
for i in range(len(k)-1):
	ans=max(ans,min(k[i],k[i+1]))
print(ans*2)