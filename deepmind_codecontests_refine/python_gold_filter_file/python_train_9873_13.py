n,a,b = map(int,input().split())
cnt = 0
for i in range(1,n+1):
    if a <= sum(map(int,str(i))) <= b:
        cnt += i
print(cnt)