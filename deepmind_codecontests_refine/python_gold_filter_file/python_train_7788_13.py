n = int(input())
l = list(input().split())
ll,lr = l[::2],l[1::2]
dl,dr = {},{}
for i in ll: dl[i] = dl.get(i,0)+1
for j in lr: dr[j] = dr.get(j,0)+1
ltl = sorted(dl.items(),key=lambda k:-k[1])
ltr = sorted(dr.items(),key=lambda k:-k[1])
if ltl[0][0] != ltr[0][0]:
  print(n-ltl[0][1]-ltr[0][1])
elif len(ltl)<2:
  print(n//2)
else:
  print(n-ltl[0][1]-max(ltl[1][1],ltr[1][1]))