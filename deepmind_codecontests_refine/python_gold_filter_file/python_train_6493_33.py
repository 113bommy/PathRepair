n = int(input())
ans = 0
for i in range(1,n):
    ans += (n-i)*i
 
ans += n
print(ans)