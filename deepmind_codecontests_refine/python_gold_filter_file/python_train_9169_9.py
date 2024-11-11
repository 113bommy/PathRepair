n=int(input())
a=list(map(int, input().split()))
cnt=1
for i in a:
    cnt=max(cnt, a.count(i))
print(cnt)