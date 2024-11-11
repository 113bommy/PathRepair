N = int(input())
ans = 0
for i in range(1,N-1):
    x = (N-1)//i
    ans += x
print(ans)