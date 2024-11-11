n = int(input())
m = 0
a = list(map(int,input().split()))
for i in range(n):
    if a[i] > m:
        print(i+1)
        exit()
    m = max(m,a[i])+1
print(-1)

