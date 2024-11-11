#D in [S_i-X_i,T_i-X_i) → Xiで止まる
import sys
input = sys.stdin.readline
from heapq import heappop,heappush
from collections import defaultdict

N,Q = map(int,input().split())
task = []

STX = [[int(x) for x in input().split()] for _ in range(N)]
for s,t,x in STX:
  task.append((t-x,0,x)) # xで止まらなくなる
  task.append((s-x,1,x)) # xで止まる

for i in range(Q):
  d = int(input())
  task.append((d,2,i)) # 止まる位置を答える
answer = [-1]*Q

task.sort()

# 引っかかってる場所の管理
se = set()
se_hp = [] # heapでソートを保つ

# 小さい時刻から順に見ていく
for a,b,c in task:
  if not b: # b == 0
    se.remove(c)
  elif b&1: # b == 1
    se.add(c)
    heappush(se_hp,c)
  else: # b == 2
    while se_hp and se_hp[0] not in se:
      heappop(se_hp)
    answer[c] = se_hp[0] if se_hp else -1

print('\n'.join(map(str,answer)))
