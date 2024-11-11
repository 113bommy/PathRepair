n = int(input())
a = input().split()
max_cnt = 0
d = {}
for i in range(n):
    if a[i] in d:
        del d[a[i]]
    else:
        d[a[i]] = 1
        if max_cnt < len(d):
            max_cnt = len(d)
print(max_cnt)
