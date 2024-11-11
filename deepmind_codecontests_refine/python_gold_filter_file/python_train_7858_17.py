input()
list = list(map(int,input().split()))
ans = 1
m = 1
for i in range(len(list)-1):
    ans = ans + 1 if list[i]<=list[i+1] else 1
    m = max(ans,m)
print(m)
