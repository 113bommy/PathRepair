n = int(input())
l = list(map(int,input().split()))
count = 0
for i in range(n):
    if i+1 == l[l[i]-1]:
        count += 1
print(count//2)