import sys

input = sys.stdin.readline

def inInt():
    return int(input())

def inStr():
    return input().strip("\n")

def inIList():
    return (list(map(int, input().split())))

def inSList():
    return (input().split())

####################################################

def solve(l, N):
  m = {}
  m[0] = 1
  re = 0
  s = 0

  for i in range(N):
    s = s + int(l[i])
    f = s - i
    if f not in m:
      m[f] = 0
    re += m[f]
    m[f] += 1

  print(re)

tests = inInt()
for t in range(tests):
    n = inInt()
    s = inStr()
    solve(s, n)