N = int(input())
ans = 0
for i in range(1, N):
    if i**2 >= N:
        break
    if (N-i)%i==0:
        ans += (N-i)//i
print(ans)