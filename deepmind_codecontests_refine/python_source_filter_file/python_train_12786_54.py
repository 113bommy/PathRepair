n = int(input())
ans = 'No'
for i in range(n//4):
    if (n - i*4)%7 == 0:
       ans = 'Yes'
print(ans)
