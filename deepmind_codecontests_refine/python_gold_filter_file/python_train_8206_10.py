n = int(input())
a = list(map(int,input().split()))
x = [0]
for i in a:
    x.append(x[-1]+i)
ans = 10**11
for i in x[1:-1]:
    ans = min(ans,abs(i*2-x[-1]))
print(ans)