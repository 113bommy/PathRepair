n,t,c = map(int,input().split())
a = list(map(int,input().split()))
temp = c
total = 0
count = 0
for i in range(0,len(a)):
    if a[i] <= t:
        count += 1
    elif a[i] > t and count >= c:
        total += count - c + 1
        count = 0
    elif a[i] > t and count < c:
        count = 0
if count > 0:
    total += count - c + 1
print(total)