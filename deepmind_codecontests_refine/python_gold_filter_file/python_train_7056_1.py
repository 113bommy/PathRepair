s = input()
q = int(input())

x = []
y = []
cnt = 0

for i in range(q):
    a = list(input().split())
    if a[0] == "1":
        x, y = y, x
        cnt += 1
    else:
        if a[1] == "1":
            x.append(a[2])
        else:
            y.append(a[2])

if cnt % 2 == 1:
    s = s[::-1]

s = ''.join(x[::-1]) + s + ''.join(y)

print(s)
