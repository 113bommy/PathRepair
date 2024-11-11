l = input().split()
n = int(l[0])
b = int(l[1])
l = input().split()
for i in range(len(l)):
    l[i] = int(l[i])
l.sort()
m = []
if len(l) == 1:
    print(0)
else:
    for i in range(n):
        if not i == n-1:
            for j in range(i + 1, n):
                if l[j] - l[i] <= b:
                    m.append(i + (n - j) - 1)
    if m == []:
        print(n)
    else:
        print(min(m))