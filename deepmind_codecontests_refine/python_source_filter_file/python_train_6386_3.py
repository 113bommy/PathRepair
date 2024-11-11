n = int(input())
l = list(map(int, input().split()))
flag = 0
for i in range(1,max(l)):
    ans=i
    for j in range(n):
        if i>l[j]:
            l[j] = 0
    for j in range(n-1):
        if l[j] == l[j+1]==0 or l[n-1]==0 or l[0] == 0:
            flag = 1
            break
    if flag == 1:
        break
if n==1:
    print(l[0])
else:
    print(ans)