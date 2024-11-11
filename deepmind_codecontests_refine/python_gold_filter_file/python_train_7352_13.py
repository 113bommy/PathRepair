n = int(input())
a = list(map(int, input().split()))
s = n
l, r = n - 1, n - 1
 
for i in range (n - 1, -1, -1):
    r = i - a[i]
    if a[i] == 0 and l == i:
        l -= 1
    if r >= 0:
        if r < l:
            s -= (l - r)
            l = r
    else:
        s -= l
        break
print(s)