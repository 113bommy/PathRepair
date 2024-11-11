n = int(input())
l = list(map(int, input().split()))
s = sum(l)
d = 0
m = 0
while m < s // 2:
    m += l[d]
    d += 1
print(d)
