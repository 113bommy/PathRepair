N=int(input())
p=list(map(int,input().split()))
count=1
for i in range(len(p)-1):
    count+=abs(p[i+1]-p[i])
print(count)