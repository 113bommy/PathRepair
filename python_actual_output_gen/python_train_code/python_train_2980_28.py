n,l,r = map(int,input().split())
mn = mx = 0
a = 1
d = 2
s = a*(d**l-1)//(d-1)
mi = s + (1*(n-l))
s = a*(d**r-1)//(d-1)
mx = s + ((2*(r-1))*(n-r))
print(mi,mx)