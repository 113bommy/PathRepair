import sys
input = sys.stdin.readline
H,W=map(int,input().split())
S=[tuple(d for d in input()) for i in range(H)]
ans=[[0 for j in range(W)] for i in range(H)]
t=0
for i in range(H):
 p=0
 for j in range(W):
  if S[i][j]==".":
   p+=1
  else:
   p=0
  ans[i][j]+=p
for i in range(H):
 p=0
 for j in range(W)[::-1]:
  if S[i][j]==".":
   p+=1
  else:
   p=0
  ans[i][j]+=p
for j in range(W):
 p=0
 for i in range(H):
  if S[i][j]==".":
   p+=1
  else:
   p=0
  ans[i][j]+=p
for j in range(W):
 p=0
 for i in range(H)[::-1]:
  if S[i][j]==".":
   p+=1
  else:
   p=0
  ans[i][j]+=p
  t=max(t,ans[i][j])
print(t-3)