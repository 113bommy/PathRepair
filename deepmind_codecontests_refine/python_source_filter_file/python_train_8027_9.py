n, k = map(int,input().split())
a = list(map(int,input().split()))

tmp = sum(a)/k
if tmp != int(tmp):
    print("NO")
    exit()
ans = 0
cnt = 0
res = []
for i in a:
    ans+=i
    cnt+=1
    if ans > tmp:
        print('NO')
        exit()
    if ans == tmp:
        res.append(cnt)
        cnt = 0
        ans = 0
print('YES')
print(*res)