n,k=map(int,input().split())
if k<(n//2 + n%2):
    print(2*(k-1)+1)
else:
    k-=n//2 + n%2
    print(2*k)
