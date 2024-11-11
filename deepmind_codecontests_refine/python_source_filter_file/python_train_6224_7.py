s = input()
n = len(s)
m = 2019
a = 0
r = [0 for _ in range(m+1)]
r[0] = 1
for i in range(0,n):
    z = (int(s[n-i-1])*pow(10,i,m) + z)%m
    a += r[z]
    r[z] += 1
print(a)
