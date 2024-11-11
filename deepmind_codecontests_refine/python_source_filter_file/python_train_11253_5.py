n=int(input())
ma=99999999999999999
ans=[1,n,0]
for i in range(2,int(n**0.5)+1):
    j=i
    k=n//i
    t=0
    #print(j,k,t)
    if n%i!=0:
        t=1
    #print(j,k,t)
    if (j+k+t)<=ma:
        ans=[j,k,t]
        ma=j+k+t
fi=[[0 for j in range(ans[1]) ]for i in range(ans[0])]
cou=n
#print(ans)
j=ans[0]
k=ans[1]
t=ans[2]
for i in range(j):
    r=0
    if t>0:
        r=1
        t-=1
    for jw in range(k+r):
        print(cou-k-r+jw+1,end=" ")
    cou-=k+r
