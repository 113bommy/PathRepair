K, S = map(int, input().split())
a = 0
for x in range(K+1):
  for y in range(K+1):
    if S-x-y<=K :
      a+=1   
print(a)