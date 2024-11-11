from math import log
def sumc(n):
    r = 0
    while n:
        r, n = r + n % 10, n // 10
    return r

n = int(input())
k =[]
for i in range(1, min(9*(int(log(n,10))+1)+1,n//2+1)):
    d = n-i
    if sumc(d) == i:
        k.append(d)
print (len(k))
for c in k:
    print (c)