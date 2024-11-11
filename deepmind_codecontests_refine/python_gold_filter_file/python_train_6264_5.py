tc=int(input())
a=[int(i) for i in input().split()]
t = max(a)
p=a.index(t)
a_r=a[p:]
a_r.sort(reverse=True)

if p==0:
  final=a_r
else:
  a_b=a[:p]
  a_b.sort()
  final=a_b+a_r
flag=0
for i in range(len(a)):
  if a[i]==final[i]:
    continue
  else:
    flag=1
if flag:
  print('No')
else:
  print('Yes')