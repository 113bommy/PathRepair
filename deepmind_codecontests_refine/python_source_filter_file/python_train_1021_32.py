h,w = map(int, input().split())
k = [list(input()) for i in range(h)]

ans = True
for i in range(0,h-1):
    for j in range(0,w-1):
        if k[i][j] == "#" and k[i-1][j] =="." and k[i][j-1] =="." and k[i+1][j] =="." and k[i][j+1] =="." :
            ans = True

if ans:
    print('Yes')

else:
    print('No')