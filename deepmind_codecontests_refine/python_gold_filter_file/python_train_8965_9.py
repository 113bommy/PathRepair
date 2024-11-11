n = int(input())
l = []
l1 = []
l2 = []
for i in range(n):
  l = list(map(int,input().split()))
  l1 = [l[0],l[1]]
  l2 = [l[2],l[3]]
  if(min(l1) == max(l2)):
    print(max(l1),min(l2))
  else:
    print(min(l1),max(l2))
