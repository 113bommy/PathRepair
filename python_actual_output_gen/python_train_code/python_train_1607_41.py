n = int(input())
count = 0
for i in range(n):
    a = list(map(int,input().split()))[:n]
    if sum(a)>1:
        count+=1
print(count)