c=0
k,n,w=map(int,input().split())
for i in range(1,w+1):
    c=c+(i*k)
if c>k:
    print(c-k)
else:
    print(0)