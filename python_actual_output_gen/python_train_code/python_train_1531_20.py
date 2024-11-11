n = int(input())
data = list(map(int, input().split()))
src, dst = map(int, input().split())
if src > dst:
    src, dst = dst, src
v1 = sum(data[src - 1: dst - src])
v2 = sum(data) - v1
print(min(v1, v2))
