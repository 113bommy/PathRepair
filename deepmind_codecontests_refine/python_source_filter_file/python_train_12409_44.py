def c (n):
    st = str(n)
    s1 = set(st)
    if len(s1) == len(st):
        return bool(1)
    else:
        return bool(0)
s = str(input())
l = s.split()
x = int(l[0])
y = int(l[1])
for i in range(x, y):
    if c(i) == bool(1):
        print(i)
        exit(0)
print(-1)