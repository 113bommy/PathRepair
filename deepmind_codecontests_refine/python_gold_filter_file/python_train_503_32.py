n,a=map(int,input().split())
x=list(map(int,input().split()))
dic={}
dic2=dic.copy()
for i in range(n):
  for j in dic:
    if j+x[i]-a in dic2:
      dic2[j+x[i]-a]+=dic[j]
    else:
      dic2[j+x[i]-a]=dic[j]
  if x[i]-a in dic2:
    dic2[x[i]-a]+=1
  else:
    dic2[x[i]-a]=1
  dic=dic2.copy()
if 0 in dic:
  print(dic[0])
else:
  print(0)