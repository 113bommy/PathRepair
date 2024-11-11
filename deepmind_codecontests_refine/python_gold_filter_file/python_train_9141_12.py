def renew(lis,id1,id2):
  tar = lis[id1]; bow = lis[id2]
  if tar[0] < bow[0]:
    tar = [bow[0],max(bow[1],tar[0])]
  else:
    tar[1] = max(bow[0],tar[1])
  lis[id1] = tar
  return

n = int(input())
a = [[x,0] for x in list(map(int, input().split()))]
for j in range(n):
  for i in range(2**n):
    if not i & (1<<j):
      renew(a,i|(1<<j),i)
a = [x+y for x,y in a[1:]]
for i in range(1,2**n-1):
  if a[i] < a[i-1]:
    a[i] = a[i-1]
for x in a:
  print(x)
