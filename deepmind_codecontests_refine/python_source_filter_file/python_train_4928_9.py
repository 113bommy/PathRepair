nab = list(map(int, input().split()))
h = list(map(int, input().split()))
n = nab[0]
a = nab[1]
b = nab[2]

sh = sorted(h)

if sh[b-1] != sh[b]:
    print(sh[b-1])
else:
    print(0)