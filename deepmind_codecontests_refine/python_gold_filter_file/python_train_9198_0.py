n, k = map(int, input().split())
p = list(map(int, input().split()))
p.sort()
t = [[i] for i in p]
for i in range(1, n):
    t += [t[-1] + i for i in t[: n - i]]
print('\n'.join(str(len(i)) + ' ' + ' '.join(map(str, i)) for i in t[: k]))