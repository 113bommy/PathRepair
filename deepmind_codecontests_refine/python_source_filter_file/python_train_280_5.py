n, k = map(int, input().split())
a = list(map(int, input().split()))

a = sorted(a)
a.append(2000000)
s = 0
i = 0
j = 0
while i < len(a)-1:
    while j < len(a) and a[j] == a[i]:
        j += 1
    if a[j] - a[i] > k:
        s += 1
    i += 1

print(s)
    
