n = int(input())
c = list(map(int,input().split()))

l = r = ""
a = b = 0
for _ in range(n):
    x = y = float("inf")
    i = input()
    rev = i[::-1]
    if i>l:
        x = a
    if i>r:
        x = min(x,b)
    if rev>l:
        y = a + c[_]
    if rev>=r:
        y = min(y,b+c[_])
    a = x; b = y; l = i; r = rev
res = min(a,b)
if res == float("inf"):
    print (-1)
else:
    print (res)
    