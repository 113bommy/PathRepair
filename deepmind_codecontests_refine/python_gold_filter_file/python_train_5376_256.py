
n = int(input())
m = int(input())

mod = 1

while n>0:
    mod *= 2
    n -= 1
    if(mod>m): break

print(m%mod)