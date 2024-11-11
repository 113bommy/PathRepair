#1 3 5 7 2 4 6
#1 3 5 2 4 6
n,k=[int(i) for i in input().split(' ')]
if n%2==1:
    if k<=(n+1)//2:
        print(2*k-1)
    else:
        print(2*(k-(n+1)//2))
else:
    if k<=n//2:
        print(2*k-1)
    else:
        print(2*(k-n//2))

