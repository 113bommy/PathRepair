k = input()
num = input().split()
num = list(map(int, num))
l = 0
t = 500000
r = 0
for i in num:
    if i <= t:
        l = i-1
    else:
        r = max(r, 1000000 - i)
print((max(l,r)))