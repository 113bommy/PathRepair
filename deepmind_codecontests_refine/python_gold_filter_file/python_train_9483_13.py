n,m = map(int,input().split())

cost = list(map(int,input().split()))
bill = list(map(int,input().split()))

j=0
count=0
for i in range(n):
    if cost[i]<=bill[j]:
        count+=1
        j+=1

    if i>=n or j>=m:
        break


print(count)
