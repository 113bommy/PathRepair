n, k = map(int,input().split())
print(int(1+(k-1)*2 if k <= (n+1)//2 else 2*(k-(n+1)//2)))