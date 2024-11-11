n,k=map(int,input().split())
p=list(map(int,input().split()))
a=0
pp=[0]
for i in p:
    a+=i
    pp.append(a)
a=0
for i in range(k,n-k+1):
    a=max(a,pp[i]-pp[i-k])

print(a/2+k/2)
