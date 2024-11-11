k = int(input())
n = 0
for i in range(1,10**6):
    n = n*10+7
    if n%k==0:
        print(i)
        exit()
print(-1)