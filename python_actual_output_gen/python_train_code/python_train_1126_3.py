n,m = map(int,input().split())
k = 0
for i in range(2,10**20):
    if i*(i-1)//2 >= m:
        k = i
        break
print(max(0,n - m*2),max(0,n-k))

