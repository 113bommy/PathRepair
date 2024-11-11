N = int(input())
M = [list(map(int, input().split())) for i in range(N)]
Q = [[m[0]-m[1], m[0]+m[1]] for m in M]
Q = list(sorted(Q, key=lambda x: x[0]))
NUM = 0
END = -10**9
for q in Q:
  if q[0] >= END:
    NUM += 1
    END = q[1]
print(NUM)