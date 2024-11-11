n = int(input())
l = 1
y = 1
x = -1
for i in range(n):
    k, m = map(int, input().split())
    m += k * 60
    if x == m:
        y += 1
    else:
        x = m
        l = y
        y = 1
if y > l:
    l = y
print(l)
#s = input()
#c = list(map(int, input().split()))
         