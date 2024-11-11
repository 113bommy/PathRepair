n = eval(input())
a = list(map(int, input().split()))
odd = False
even = False
for i in range(n):
    if a[i] & 1:
        odd = True
    else:
        even = True
if odd & even:
    a.sort()
for x in a:
    print(x, end=" ")