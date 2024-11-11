n = int(input())
for a in range(1,n):
    for b in range(1,a//2+1):
        if a % b == 0:
            if a*b > n and a/b < n:
                print(a,b)
                exit()
print(-1)