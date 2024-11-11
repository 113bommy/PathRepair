n, w, b = map(int, input().split())
a = list(map(int, input().split()))
i = 0
j = n - 1
f = False
s = 0
while i != j:
    if a[i] != a[j] and a[i] != 2 and a[j] != 2:
        f = True
    elif (a[i] == 0 and a[j] == 2) or (a[i] == 2 and a[j] == 0):
        s += w
    elif (a[i] == 0 and a[j] == 1) or (a[i] == 1 and a[j] == 0):
        s += b
    elif a[i] == 2 and a[j] == 2:
        s += min(w, b)*2
    i += 1
    j -= 1
    if i > j:
        break
if a[i] == 2 and n % 2 != 0:
    s += min(w, b)
print(s if not f else -1)
