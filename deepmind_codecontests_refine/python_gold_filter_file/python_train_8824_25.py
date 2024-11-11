n=int(input())
ans = 0
for i in range(1, n+1):
    ans += (n//i) * ((n//i)+1)//2*i;
print(ans)