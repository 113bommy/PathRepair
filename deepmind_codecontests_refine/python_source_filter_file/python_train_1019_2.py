import sys
input=sys.stdin.readline
N=int(input())
S=input()
w=S.count('.');c=w
for i in range(N):
  if S[i]=='.':
    c-=1
  else:
    c+=1
  c=min(c,w)
print(c)