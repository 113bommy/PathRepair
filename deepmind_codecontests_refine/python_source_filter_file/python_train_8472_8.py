n,k = map(int,input().split())
print(2*k-1 if k<(n+1)/2 else 2*(k-(n+1)//2))