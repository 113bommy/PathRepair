n = int(input())
cnt = 0
for i in range(1,n+1):
    if i*(1+i)//2 >= n:
        cnt = i
        break
for i in range(cnt, 0, -1):
    if i <= n:
        print(i)
        n -= i