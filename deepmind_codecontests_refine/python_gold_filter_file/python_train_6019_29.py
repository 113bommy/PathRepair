import sys
MAX_INT = int(10e10)
MIN_INT = -MAX_INT
mod = 1000000007
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N = I()
C = [I() for i in range(N)]

dic = {}

ans = 0
tmp = "None"
for i in C:
  if i == tmp:
    continue
  else:
    tmp = i
    if i not in dic:
      dic[i] = ans
    else:
      ans += dic[i] + 1
      dic[i] = ans

print((ans+1)%mod)