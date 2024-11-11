import sys
input = sys.stdin.readline
l = int(input())
s = input().rstrip()
n = int(input())
q = [input().rstrip() for i in range(n)]
ls = [[0 for i in range(26)] for j in range(l+1)]
for i in range(l):
  if i > 0:
    ls[i] = ls[i-1][:]
  ls[i][ord(s[i])-97] += 1
def judge(lis,x):
  for i,j in zip(lis,x):
    if i < j:
      return False
  return True
for t in q:
  x = [0]*26
  for i in range(len(t)):
    x[ord(t[i])-97] += 1
  lf = 0
  rg = l+1
  while lf+1<rg:
    m = (lf+rg)//2
    if judge(ls[m],x):
      rg = m
    else:
      lf = m
  print(rg+1)