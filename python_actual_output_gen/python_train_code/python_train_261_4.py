n = int(input())
m = 0
a = list(map(int,input().split()))
for i in range(n):
    if a[i] > m+1:
        print(i+1)
        exit()
    m = max(m,a[i])
print(-1)

