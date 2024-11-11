n, m, a, b = map(int,input().split())
print(((m*(n//m+1)-n)*a), ((n - (m*(n//m)))*b) )