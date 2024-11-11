n = int(input())
lst = list(map(int, input().split()))
mini = lst[0]
maxi = lst[0]
ans = 0
for x in lst[1:]:
    if(x < mini):
        mini = x
        ans += 1
    if(x > maxi):
        maxi = x
        ans += 1
print(ans)
