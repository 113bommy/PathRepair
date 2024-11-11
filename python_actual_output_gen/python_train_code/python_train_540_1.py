n,a,b = map(int,input().split())

a -= 1
b -= 1
ans = 0
temp = 2
for i in range(8):
    if a // temp == b // temp:
        ans = i + 1
        break
    temp *= 2
    
if temp == n:
    print("FINAL!")
else:
    print(ans)
