n, a, b, l, r = int(input()), list(map(int, input().split())), input(), -10**9, 10**9
for i in range(4, n):
    if b[i-4:i+1]=="00001": l = max(l, max(a[i-4:i+1])+1)
    if b[i-4:i+1]=="11110": r = min(r, min(a[i-4:i+1])-1)
print(l, r)