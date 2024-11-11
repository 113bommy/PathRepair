N=int(input())
p=[0]+list(map(int,input().split()))
count=0
for i in range(len(p)-1):
    count+=abs(p[i+1]-p[i])
print(count)