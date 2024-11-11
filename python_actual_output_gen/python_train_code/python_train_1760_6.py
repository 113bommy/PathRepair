N = int(input())
n = list(map(int,input().split()))
ans  = 0
for i in range(N):
    if n[n[i]-1] == i:
        ans += 1 
print(ans / 2)