h,w,n = map(int,input().split())
sr,sc = map(int,input().split())
t = input()
s = input()
hei = [1,h]
wid = [1,w]
for i in range(n-1,-1,-1):
  if s[i] == "L":
    wid[1] = min(wid[1]+1,w)
  elif s[i] == "R":
    wid[0] = max(wid[0]-1,0)
  elif s[i] == "U":
    hei[1] = min(hei[1]+1,h)
  elif s[i] == "D":
    hei[0] = max(hei[0]-1,0)
  if t[i] == "L":
    wid[0] += 1
  elif t[i] == "R":
    wid[1] -= 1
  elif t[i] == "U":
    hei[0] += 1
  elif t[i] == "D":
    hei[1] -= 1
  if wid[0]==wid[1] or hei[0]==hei[1]:
    print("NO")
    exit(0)
if hei[0] <= sc <= hei[1] and wid[0] <= sr <= wid[1]:
  print("YES")
else:
  print("NO")