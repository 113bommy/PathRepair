h1,m1,h2,m2,k = map(int,input().split())

m = m2-m1 + (h2-h1)*60
print(m-k)
