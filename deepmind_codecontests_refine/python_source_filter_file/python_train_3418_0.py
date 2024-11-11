a=[list(map(int,input().split())) for i in range(3)]
for i in range(2):
    for j in range(2):
        if a[i][j]-a[i][j+1]==a[i+1][j]-a[i+1][j+1]:
            continue
        else:print("NO");exit()
print("YES")   