K,S=map(int,input().split())
print(sum(1for x in range(K+1)for y in range(K+1)if0<=S-x-y<=K))
