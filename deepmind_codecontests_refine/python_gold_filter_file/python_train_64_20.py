q = int(input())
w = list(map(int,  input().split()))
z = 1
x = 1000000
t = 0
v = 0
for i in w:
    if i <= x // 2:
        t = i - z
    else:
        v = x - i
        break
print(max(v,  t))
