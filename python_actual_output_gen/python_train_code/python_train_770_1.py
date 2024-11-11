def solve(n,a):
    a.sort()
    odd,even = 0,0
    for i in range(n):
        if a[i]&1:odd+=1
        else:even+=1
    one = 0
    for i in range(1,n):
        if a[i]-a[i-1]==1:one += 1
    flag = True
    if odd%2==1 and one%2==0:
        flag =False
    if flag:print("YES")
    else:print("NO")

for i in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    solve(n,a)