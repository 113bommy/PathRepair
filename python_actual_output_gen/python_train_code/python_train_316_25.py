n = int(input())
*l, = map(int,input().split())
l = l.sort()
ans=l[0]
for i in l:
  ans = ans/2 + i/2
print(ans)