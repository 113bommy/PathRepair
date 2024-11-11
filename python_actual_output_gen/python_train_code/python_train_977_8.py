n,m,d = map(int,input().split())
print(2*(m-1)*(n-d)/n/n if m > 0 else (m-1)/n)
