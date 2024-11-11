t = int(input())
for i in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  id = 0
  ans = 0
  while id < n:
    maxx = 0
    while (id < n and a[id] > 0):
      maxx = max(maxx, a[id])
      id+=1
    ans += maxx
    minn = -1000000000
    while(id< n and a[id] == 0):
      id+=1
    while(id< n and a[id]< 0):
        minn = max(minn, a[id])
        id+=1
    if(minn != -1000000000):
      ans += minn      
  print(ans)