n = int(input())
t = list(map(int,input().split()))
t.sort()
sum = 0
count = 0
for i in range(1,len(t)):
    if sum <= t[i]:
        count+=1
        sum += t[i]
print(count)