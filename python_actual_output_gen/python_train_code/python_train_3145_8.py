n=int(input())
a=list(map(int, input().split()))
cnt=1
for i in range(n):
    cnt=max(cnt, a.count(i))
print(cnt)