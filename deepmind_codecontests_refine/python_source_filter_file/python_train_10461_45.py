k,n,w=input().split( )
k=int(k)
n=int(n)
w=int(w)
s=0
for i in range(1,w+1):
    s=s+i*k
if s>n:
    print(s-n)
if s<n:
    print(0)
