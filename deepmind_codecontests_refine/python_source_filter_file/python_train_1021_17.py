h,w=map(int,input().split())
L=[list(input()) for i in range(h)]
for i in range(h):
    for j in range(w):
        if L[i][j]=='#':
            if L[i][max(i-1,0)]!='#' and L[i][min(i+1,w-1)]!='#' and L[max(i-1,0)][j]!='#' and L[min(i+1,h-1)][i]!='#':
                print('No')
                exit()
print('Yes')