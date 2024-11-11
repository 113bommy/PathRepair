h,w=map(int,input().split())
l=[['#' for i in range(w+2)] for j in range(2)]
l[1:1]=[list('#'+input()+'#') for i in range(h)]
p=[]
for i in range(1,h+1):
  for j in range(1,w+1):
    if l[i][j]=='#':
      p.append((i,j))
d=[(-1,0),(1,0),(0,-1),(0,1)]
r=-1
while len(p)!=0:
  r+=1
  s=[]
  for i, j in p:
    for di, dj in d:
      di+=i
      dj+=j
      if l[di][dj]=='.':
        l[di][dj]='#'
        s.append((di,dj))
  p=s
print(r)