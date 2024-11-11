n = int(input())
a = []
b = []
for i in range(n):
    s = input().split(" ")
    a.append(int(s[0]))
    b.append(int(s[1]))
minn = min(a)
maxx = max(b)
for i in range(n):
    if a[i] <= minn and b[i] >= maxx:
        print(i)
        exit()
print(-1)