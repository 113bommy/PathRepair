a = input()
a = a.split()
a,b = int(a[0]),int(a[1])

k2 = b*(b-1)*a // 2 
k = (b-1)*b*(1+a)*a // 2
res = (k + k2) % 1000000007
print(res)