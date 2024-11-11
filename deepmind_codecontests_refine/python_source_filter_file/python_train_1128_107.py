N = int(input())
A = list(map(int, input().split()))
C = [0] * 9
for a in A:
    C[min(8, a//400)] += 1
s = sum([c > 0 for c in C[:-1]])
print(C)
print(max(s, 1), s + C[-1])
