def Pow5(n):
    s = 0
    while n:
        s+= (n // 5)
        n//= 5
    return s

k = int(input())
r = -1
for n in range(0, 5 * k + 1, 5):
    t = Pow5(n)
    if(t == k):
        r = n

if r == -1:
    print(0)
else:
    print(5)
    s = ""
    for i in range(0, 5):
        s+= (str)(r + i) + ' '
    print(s)
