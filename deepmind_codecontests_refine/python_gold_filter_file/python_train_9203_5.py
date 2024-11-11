n = int(input())
a = [[],[],[],[]]
for i in range(4):
    a[i] = list(map(int, input().split()))
ans = [-1]
flag = False;
for i in range(4):
    for j in range(2):
        for k in range(2, 4):
            if(a[i][j] + a[i][k] <= n):
                flag = True;
                ans = [i + 1, a[i][j], n - a[i][j]]
                break
        if(flag):
            break
    if(flag):
        break

for i in ans:
    print(i)