n, b = [int(x) for x in input().split(' ')]
a = [int(x) for x in input().split(' ')]
splits = []
rc = 0
for i in range(n-1):
    rc += (-1) ** a[i]
    if rc == 0:
        splits.append(abs(a[i] - a[i-1]))
splits.sort()
rs = 0
cnt = 0
for s in splits:
    rs += s
    if rs <= b:
        cnt += 1
    else:
        break

print(cnt)
