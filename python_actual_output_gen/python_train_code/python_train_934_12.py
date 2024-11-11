n = input()

words = [w for w in input().split(' ')]

m = 0

caps = list("ABCDEFGHIJKLMNOPQRSTUVXYZ")

for w in words:
  cnt = 0  
  for i in w:
    if i in caps:
      cnt+=1
  if cnt > m:
    m = cnt

print(m)
