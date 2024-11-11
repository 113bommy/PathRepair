n,m = map(int, input().split())
if (n==m):
    print(m)
elif (n-m+1)/n > m/n:
    print(m+1)
else:
    print(m-1)
