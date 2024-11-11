K,S=map(int,input().split())
b=sum(0<=S-x-y<=K  for x in range(K+1)for y in range(K+1))
print(sum