from collections import Counter
n=int(input())
V=list(map(int,input().split()))
v1=Counter(V[::2]).most_common()
v2=Counter(V[1::2]).most_common()
if len(v1) ==1:
  v1.append([0,0])
if len(v2) == 1:
  v2.append([0,0])
if v1[0][0]==v2[0][0]:
  if v1[0][1]>v2[0][1]:
    print(n-v1[1][1]-v2[0][1])
  else:
    print(n-v1[0][1]-v2[1][1])
else:
  print(n-v1[0][1]-v2[0][1])