H,W=map(int,input().split())
S=[]
for _ in range(H):
    a=["."]
    a.extend(list(map(str,input())))
    a.append(".")
    S.append(a)

S.insert(0,["."]*(W+2))
S.insert(H+1,["."]*(W+2))

# print(S)

for i in range(1,H+1):
    for j in range(1,W+1):
        if S[i][j]=='.':
            S[i][j]=str((S[i-1][j-1:j+2]+S[i][j-1:j+2]+S[i+1][j-1:j+2]).count('#'))
    print(''.join(S[i][1:-1]))