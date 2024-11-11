h,w = map(int, input().split())
k = [list(input()) for i in range(h)]

ans = True
for i in range(1,h-2):
    for j in range(1,w-2):
        if k[i][j] == "#" and k[i-1][j] =="." and k[i][j-1] =="." and k[i+1][j] =="." and k[i][j+1] =="." :
            ans = True

if ans:
    print('Yes')

else:
    print('No')