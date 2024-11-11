M = int(input())
dc = [list(map(int,input().split())) for _ in range(M)]
ans = 0
s = 0
for i in dc:
  d = i[0]
  c = i[1]
  ans += c
  s+=d*c
  if s>=10:
    t = (s-1)//9
    ans+=t
    s-= t*9

ans -= 1
print(ans)