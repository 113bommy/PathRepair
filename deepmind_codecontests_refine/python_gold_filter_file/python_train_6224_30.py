s=input()
n=len(s)
a=0
t=1
d=[1]+[0]*2018
 
for i in range(n):
    a+=int(s[n-1-i])*t
    a%=2019
    t*=10
    t%=2019
    
    d[a]+=1

ans=0
for i in d:
    ans+=i*(i-1)//2
 
print(ans)