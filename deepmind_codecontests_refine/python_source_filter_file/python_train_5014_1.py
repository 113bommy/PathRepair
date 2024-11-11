def Input():
    tem = input().split()
    ans = []
    for it in tem:
        ans.append(int(it))
    return ans

s = input()
n = len(s)
if n<4:
    print(s[0])
else:
    m = n//2
    l, r = 0, n-1
    ans = [[] for i in range(2)]
    while l+1<r:
        if s[l+1]==s[r]:
            ans[0].append(s[l+1])
            ans[1].append(s[r])
        elif s[l+1]==s[r-1]:
            ans[0].append(s[l+1])
            ans[1].append(s[r-1])
        elif s[l]==s[r]:
            ans[0].append(s[l])
            ans[1].append(s[r])
        else:
            ans[0].append(s[l])
            ans[1].append(s[r-1])
        l+=2
        r-=2
    for i in range(len(ans[0])):
        print(ans[0][i],end='')
    if l<r:
        print(s[l],end='')
    for i in range(len(ans[1])-1,-1,-1):
        print(ans[1][i],end='')
    print()
