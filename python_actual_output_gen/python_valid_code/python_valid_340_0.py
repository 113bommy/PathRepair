#解説参照
n = int(input())
a = list(map(int, input().split( )))

dp = 1
for i in range(n):
    dp |= dp<<a[i]
ans = (sum(a)+1)//2
tmp = 1<<sn
for i in range(ans):
    if dp&tmp:
        print(ans)
        exit()
    ans+=1
    tmp <<=1 
print(ans)