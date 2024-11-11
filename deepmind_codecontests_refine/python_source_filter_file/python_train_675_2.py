n = int(input())
a = [list(map(int,input().split())) for i in range(n)]
ans = [n for i in range(n)]

for num in range(5):
    lol = 0
    c = 0
    for i in range(len(a)):
        if (a[i].count(num) > c):
            lol = i
            c = a[i].count(num)
    ans[lol] = num
print(*ans)            

