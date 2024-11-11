from sys import stdin, stdout


n = int(stdin.readline())
s_a = [1 for _ in range(n+1)]
for i in range(2, n):
    for j in range(i*2, n, i):
        s_a[j] = i
s_a.sort()
s_a.pop(0)
s_a.pop(0)

stdout.write(' '.join(map(str, s_a)))
