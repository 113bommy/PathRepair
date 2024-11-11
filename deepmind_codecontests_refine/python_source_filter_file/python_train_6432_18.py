n = int(input())
x = list(map(int,input().split()))
c = sum(x)//n
ans = 0
for i in x:
    ans +=(i-c)**2
print(ans)