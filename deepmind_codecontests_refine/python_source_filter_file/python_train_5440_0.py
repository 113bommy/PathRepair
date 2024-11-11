n,p = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
ans = 0
ansls = []
mx = max(a)
mn = max([a[i]-i for i in range(n)])
ansmx = -1
for j in range(p,n)[::-1]:
  ansmx = max(ansmx,n-max(mn,a[j])+mn-(n-j-1))
while ansmx < p:
  ans += 1
  ansls.append(mn)
  mn += 1
  ansmx += 1
print(ans)
print(*ansls)