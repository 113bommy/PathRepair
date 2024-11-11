n,k=map(int,input().split())
a=[]
for i in range(n+1):
    a.append(len(input()))
l=a[n]

a=a[:n]
a=sorted(a)
r=0
t=0
for i in range(n):
    if a[i]<=l:
        t+=1 
    if a[i]<l:
        r+=1

d1=r+(r//k)+1 
d2=t+(t-1)//k
print(d1,d2,sep=" ")