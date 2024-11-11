n , m = input().split()
n = int(n)
m = int(m)

a= input().split()
for i in range(len(a)):
    a[i] = int(a[i])

a.sort()
# print(a)

money = 0
mid = True

for i in range(m):
    if a[i] >= 0:
        mid = False
    
    if mid:
        money -= a[i]
    else:
        break

print(money)