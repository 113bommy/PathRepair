import sys
input = sys.stdin.buffer.readline

N = int(input())
issame = True
s = 0
B_min = 10 ** 9 + 7
for _ in range(N):
    A, B = map(int, input().split())
    s += B
    if issame:
        issame = (A == B)
    if A >= B and B_min > B:
        B_min = B

print(0 if issame else s - B_min)