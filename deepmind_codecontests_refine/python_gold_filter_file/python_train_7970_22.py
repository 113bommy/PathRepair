n,k=map(int,input().split())
l=240-k
x=5
i=0
while x<=l and i<n:
    i+=1
    x+=(5*(i+1))
print(i)

