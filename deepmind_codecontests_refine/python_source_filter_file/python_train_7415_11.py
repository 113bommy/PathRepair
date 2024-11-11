n,k = map(int,input().split())

a= list(map(int,input().split()))
x=n-k

an = n*(n+1)//2 - (x)*(x+1)//2 
#print(an)

rang = list(range(n,n-k,-1))
h=[0]*1000000
for i in range(len(rang)):
    h[rang[i]]+=1
ans = []
pa =1 
m=998244353 
for i in range(n):
    if h[a[i]]==1 :
        ans.append(i)
for i in range(1,len(ans)):
    pa=(pa%m)*((ans[i]-ans[i-1])%m)
print(an,pa)