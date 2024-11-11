n = int(input())
a = list(map(int,input().split()))
count = 0
for i in range(n):
    if i+1 == a[i-1]:
        count+=1
print(count//2)