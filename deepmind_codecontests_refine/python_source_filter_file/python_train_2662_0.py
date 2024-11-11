n, a, b = map(int, input().split())
s = input()
e = list(s)
d = 0
c = 0
if(a>b):
    a,b = b,a
for i in range(n):
    if(a == i):
        d = e[i-1]
    if(b == i):
        c = e[i-1]
print(abs(int(d)-int(c)))

