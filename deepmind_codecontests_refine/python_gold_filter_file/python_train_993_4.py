n = int(input())

s = input()

a = [0] * n

for i in range(n):
    if s[i] == 'r':a[i] = 1
    
u = v = 0
    
for i in range(n):
    if i % 2 == 0:
        if a[i] != 1:u += 1
    else:
        if a[i] != 0:v += 1
ans1 = max(u, v)

u = v = 0

for i in range(n):
    if i % 2 == 0:
        if a[i] != 0:u += 1
    else:
        if a[i] != 1:v += 1

ans2 = max(u, v)
print(min(ans1, ans2))
        