n = 10**6
a = [1]*n
s = set()
for i in range(2, n):
    if a[i] == 1:
        s.add(i*i)
        for j in range(i*i, n, i):
            a[j] = 0
tt = int(input())
arr = map(int, input().split())
for x in arr:
    if x in s:
        print('yes')
    else:
        print('no')
