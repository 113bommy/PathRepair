h,w,k=map(int,input().split())
s=[list(map(int,input().replace("#",'1').replace(".",'0'))) for i in range(h)]
a=s
tmp=1

for i in range(h):
  if sum(s[i])>0:
    for j in range(w):
      if s[i][j] == 1 and sum(s[i][j+1:])>0:
        a[i][j]=tmp
        tmp+=1
      elif j==w-1:
        a[i][j]=tmp
        tmp+=1
      else:
        a[i][j]=tmp

flg=0
for i in range(h):
  if flg>0 and sum(s[i])==0:
    s[i]=s[i-1]
  else:
    flg=i
for i in reversed(range(h)):
  if sum(s[i])==0:
    s[i]=s[i+1]
for i in range(h):
  print(' '.join(list(map(str,a[i]))))