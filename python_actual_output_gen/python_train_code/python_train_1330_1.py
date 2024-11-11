# 1143B.py
n = int(input())
x = n
cnt = 0
while x>0:
    cnt+=1
    x//=10
# print(cnt)
l = []
for i in range(1,cnt):
    p = n%(10**i)
    p+=1
    l.append(n-p)
# print(*l)
ans = 1
for i in range(cnt-1):
    prod = 1
    while l[i]>0:
        prod*=(l[i]%10)
        l[i]//=10

    ans = max(ans,prod)
print(ans)