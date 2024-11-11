n = int(input().strip())

num = [1 for x in range(n+1)]
num[0] = num[1] = 0

ans = 0

for x in range(2,n+1,1):
    if num[x] == 1:
        ans += 1
    for y in range(2,x,1):
            if x%y != 0 and x*y <= n:
                num[x*y] = 0
                
print(ans)
for x in range(n+1):
    if num[x] == 1:
        print(x,end=" ")