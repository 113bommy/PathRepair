h,w,n = map(int,input().split())
sr,sc = map(int,input().split())
s = input()
t = input()
r,l,u,d = sc,sc,sr,sr
ans = "YES"
for i,j in zip(s,t):
  if i == "R":
    r+=1
    if r>w:
      ans = "NO"
      break
  elif i =="L":
    l-=1
    if l<1:
      ans = "NO"
      break
  elif i =="U":
    u-=1
    if u<1:
      ans = "NO"
      break
  else:
    d+=1
    if d<1:
      ans = "NO"
      break
  if j == "L":
    r=max(1,r-1)
  elif j == "R":
    l=min(w,l+1)
  elif j == "D":
    u=min(w,u+1)
  else:
    d=max(1,d-1)
print(ans)