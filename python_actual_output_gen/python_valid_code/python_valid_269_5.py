m = int(input())
n = list(map(int,input().split()))

n.sort()
SUM = 0
count = 0
for i in range(len(n)-1):
    SUM += n[i]
    if n[i+1] > SUM*2:
        count += 1
print(len(n)-count)
    

