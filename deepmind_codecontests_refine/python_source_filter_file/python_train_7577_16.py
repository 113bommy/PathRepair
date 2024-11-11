"""
N = int(input())
A, B = map(int,input().split())
lst = [list(map(int,input().split())) for i in range(M)]
A = list(map(int,input().split()))
"""

import math

mod = int(1e9+7)

N = int(input())
S = input()

""" 
##for test
N = 100000
S = 'B'*(2*N)
#print(S)
"""

rest = 0
cnt = 1
for i in range(2*N):
  if (i%2 == 0 and S[i]=='B') or (i%2 == 1 and S[i]=='W'): ## 続行
    rest += 1
  else: ## 枝を一つ繋げる
    if rest < 1: ## 繋げる枝がない場合
      print(0)
      exit()
    else:
      cnt = (cnt * rest) % mod
      rest -= 1
else:
  if rest != 0: ## 繋ぐことのできなかった枝が残っている場合
    print(0)
    exit()

ans = cnt * (math.factorial(N) % mod)
print(ans)