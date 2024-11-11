n, k=map(int, input().split());
if n==1 : 
    if k==0 :
        print(1)
        exit(0)
    else :
        print(-1)
        exit(0)
if k<n//2 :
    print(-1)
    exit(0)
x=k-(n-2)//2
print(x, x+2, end=' ')
for i in range(2, n) : 
    print(x*2+i, end=' ')