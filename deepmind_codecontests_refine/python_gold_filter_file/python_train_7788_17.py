import collections

N = int(input())
a = list(int(i) for i in input().split())

b = a[::2]
c = a[1::2]

b_ =collections.Counter(b)
c_ =collections.Counter(c)

baa = b_.most_common()
caa = c_.most_common()

baa.append([0,0])
caa.append([0,0])

if baa[0][0] != caa[0][0]:
    print(N - baa[0][1] - caa[0][1])
else:
    print(min(N - baa[0][1] - caa[1][1],N - caa[0][1] - baa[1][1]))