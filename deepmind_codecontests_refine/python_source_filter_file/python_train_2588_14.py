from collections import defaultdict
h,w,n = map(int,input().split())
x = []
for i in range(n):
  x.append(list(map(int,input().split())))
d = defaultdict(int)
for i in x:
  a = []
  for j in range(3):
    for k in range(3):
      if (i[0]-j-1>=0 and i[1]-k-1 >= 0 and i[0]-j-1<=h-3 and i[1]-k-1 <= w-3):
        a.append((i[0]-j-1,i[1]-k-1))
  for j in a:
    d[j] += 1
a = list(d.values())
ans = [0]*9
ans[0] = (h-2)*(w-2)-len(a)
for i in a:
  ans[i-1] += 1
for i in ans:
  print(i)