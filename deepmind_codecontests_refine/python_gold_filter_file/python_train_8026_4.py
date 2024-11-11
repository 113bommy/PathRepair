a = int(input())
max = 0
for i in range(a):
  x , y = map(int,input().split())
  l = ((x) + (y))
  if max < l:
    max = l
    mx = x
    my = y
print(mx+my)