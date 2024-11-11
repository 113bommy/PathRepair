x = input()
y = list(map(int, input().split(" ")))

a = 0
z = max(y)
for i in y:
    a += z - i

print(a)
