import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = ir()
A = [ir() for _ in range(N)]
answer = A[0] - 1
cur_limit = 2
for a in A[1:]:
    if a == cur_limit:
        cur_limit += 1
        continue
    answer += -((-(a-cur_limit)) // cur_limit)

print(answer)
# 44