n = int(input())
t = [1] * (n+1)

for i in range(2, n+1):
    for j in range(i * i, n+1, i):t[j] = 2
if n>2:
    print(2)
else:
    print(1)
print(*t[2:])


