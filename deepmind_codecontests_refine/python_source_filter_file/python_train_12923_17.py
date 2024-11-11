from copy import deepcopy
n,b = map(int, input().split())


i = 2
arr = []
c_n = n
while i * i <= b:
    t = 0
    while b % i == 0:
        t+=1
        b /= i
    if t:
        arr.append((i, t))
    i+=1
if b != 1:
    arr.append((b, 1))
mn = None
for i, t in arr:
    c_n = n
    k = 0
    while c_n >= i:
        k+= c_n/i
        c_n/=i
    if mn == None:
        mn = k // t
    mn = min(mn, k//t)
print(int(mn))
