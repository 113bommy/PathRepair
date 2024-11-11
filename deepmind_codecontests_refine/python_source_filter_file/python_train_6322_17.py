a,b = map(int, input().split())
c = list(map(int, input().split()))
count = 0
for i in range(a):
    if c[i] <= b:
        count += 1
    else:
        break
for j in range(a-1,0,-1):
    if c[j] <= b:
        count += 1
    else:
        break
print(count) if count > a else count