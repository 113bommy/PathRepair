
N,M=map(int,input().split())

p=0
q=100000000000000

for i in range(M):
    l,r=map(int,input().split())
    p=max(p,l)
    q=min(q,r)
print(q-p+1)
