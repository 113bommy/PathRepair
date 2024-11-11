import sys

N = int(input())

if (N & -N) == N:
    print('No')
    sys.exit()

N2 = N if N%2 else N-1
anss = []
for i in range(2, N2+1):
    anss.append((1, i))
for i in range(2, N2+1):
    anss.append((i, (i^1)+N))
anss.append((2+N, 1+N))

if N%2 == 0:
    N2 = N+1
    k = 1<<(N2.bit_length()-1)
    anss.append((N, k))
    anss.append((N, N2^k))

print('Yes')
print('\n'.join(map(lambda x: str(x[0])+' '+str(x[1]), anss)))
