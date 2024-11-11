from collections import Counter

N = int(input())
C = Counter(input())

for n in range(N-1):
    C&=Counter(input())

print(*C.elements(),sep="")