n, x = [int(x) for x in input().split()]
currentMin = 1
res = 0
for i in range (n):
    l, r = [int(x) for x in input().split()]
    res += (l - currentMin) % x + (r - l + 1)
    currentMin =  + 1
print(res)