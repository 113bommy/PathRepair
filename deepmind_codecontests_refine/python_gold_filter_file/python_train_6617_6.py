n, n1, n2 = map(int,input().split())
l = list(map(int,input().split()))
l.sort(reverse=True)
# print(l)
ans = 0
if n1>n2:
    ans1 = 0
    for i in range(n2):
        ans1+=l[i]
    ans2 = 0
    for j in range(n2, n1+n2):
        ans2+=l[j]

    ans = (ans1/n2)+(ans2/n1)
else:
    ans1 = 0
    for i in range(n1):
        ans1+=l[i]
    ans2 = 0
    for j in range(n1, n1+n2):
        ans2+=l[j]

    ans = (ans1/n1)+(ans2/n2)
    # print(ans1, ans2)
print(ans)