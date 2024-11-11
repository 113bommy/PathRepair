h,w=map(int, input().split())
s=[' '*(w+2)]
for _ in range(h):
    s.append(' '+input()+' ')
s.append(' '*(w+2))

for i in range(1,w+1):
    for j in range(1,h+1):
        if s[j][i]=='#':
            if s[i-1][j]!='#' and s[i+1][j]!='#' and s[i][j-1]!='#' and s[i][j+1]!='#' :
                    print('No')
                    exit()
print('Yes')
