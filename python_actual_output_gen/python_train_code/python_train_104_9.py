N = int(input())
p = list(map(int,input().split()))
ans = 0
c = 0
for i in range(N-1):
    if p[i] == i+1:
        c += 1
    else:
        ans += (c+1)//2
        c = 0
print(ans+(c+1)//2)