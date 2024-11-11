
n,k=map(int,input().split())
s=input()

I=[0]

for i in range(n-1):
    if s[i]!=s[i+1]:
        I.append(i+1)
        
r=len(I)

for _ in range(10**6):
        I.append(n)

X=[]

for i in range(r):
    if s[I[i]]=='0':
        X.append(I[i+2*k]-I[i])
    else:
        X.append(I[i+2*k+1]-I[i])

print(max(X))
    