import sys
input = sys.stdin.readline

class BIT:
    def __init__(self, size):
        self.bit = [0] * (size + 1)
        self.size = size

    def sum(self, i):
        i += 1
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def add(self, i, x):
        i += 1
        while i <= self.size:
            self.bit[i] += x
            i += i & -i

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
ans = float('inf')
for b in range(1 << N):
    even = []
    odd = []
    for i in range(N):
        if b >> i & 1:  # red
            if i % 2 == 0:
                even.append((A[i], i))
            else:
                odd.append((A[i], i))
        else:  # blue
            if i % 2 == 0:
                odd.append((B[i], i))
            else:
                even.append((B[i], i))
    if len(even) != (N + 1) // 2 or len(odd) != N // 2:
        continue
    even.sort()
    odd.sort()
    num = []
    for i in range(len(odd)):
        num += [even[i], odd[i]]
    if N % 2 == 1:
        num += [even[-1]]
    ok = True
    for i in range(N-1):
        if num[i] > num[i+1]:
            ok = False
            break
    if not ok:
        continue
    tmp = 0
    bit = BIT(N)
    for i in range(1, N):
        bit.add(i, 1)
    for i in range(N):
        j = num[i][1]
        tmp += bit.sum(j) - i
        bit.add(0, 1)
        bit.add(j, -1)
    ans = min(ans, tmp)
print(ans if ans < float('inf') else -1)