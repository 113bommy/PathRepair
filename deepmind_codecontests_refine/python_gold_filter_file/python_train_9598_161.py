n, x, y = map(int,input().split())
print(n-max(x+1,n-y)+1)