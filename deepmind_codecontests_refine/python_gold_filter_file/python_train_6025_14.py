N,L=map(int,input().split())
a=list(map(int,input().split()))

x=-1
for i in range(0,N-1):
    if a[i]+a[i+1]>=L:
        x=i
        break
if x==-1:
    print("Impossible")
else:
    print("Possible")
    for i in range(N-1, x+1,-1):
        print(i)
    for i in range(0,x+1):
        print(i+1)