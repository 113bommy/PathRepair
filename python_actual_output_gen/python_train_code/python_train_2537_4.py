import sys
input = sys.stdin.readline

n, b, d = map(int, input().split())
oranges = [int(x) for x in input().split()]
tot = 0
cnt = 0

for o in oranges:
    tot += o if o <= b else 0
    if tot > d:
        tot -= d
        cnt += 1

print(cnt)
