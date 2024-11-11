n=int(input())
s=list(map(int,input().split()))
t=list(map(int,input().split()))
u=list(map(lambda x:'0'*64+bin(int(x))[2:],input().split()))
v=list(map(lambda x:'0'*64+bin(int(x))[2:],input().split()))
ans=[[0]*n for _ in range(n)]
for i in range(65): # 2^iの位で考える
    ansi=[[-1]*n for _ in range(n)] # -1で残ったものは0とみなす
    for r in range(n): # 和で0、積で1の行と列に値を入れる。
        if s[r]==1 and u[r][-i-1]=='0':
            for c in range(n):
                ansi[r][c]=0
        elif s[r]==0 and u[r][-i-1]=='1':
            for c in range(n):
                ansi[r][c]=1
    for c in range(n):
        if t[c]==1 and v[c][-i-1]=='0':
            for r in range(n):
                if ansi[r][c]==-1:
                    ansi[r][c]=0
                elif ansi[r][c]==1:
                    print(-1)
                    exit(0)
        elif t[c]==0 and v[c][-i-1]=='1':
            for r in range(n):
                if ansi[r][c]==-1:
                    ansi[r][c]=1
                elif ansi[r][c]==0:
                    print(-1)
                    exit(0)
    for r in range(n):
        for c in range(n):
            if ansi[r][c]==-1 and u[r][-i-1]==v[c][-i-1]:
                ansi[r][c]=int(v[c][-i-1])

    for r in range(n): #行に対する操作
        if s[r]==1 and u[r][-i-1]=='1' and 1>max(ansi[r]): #和で1の行だが、まだ1がない
            ok=False
            for c in range(n):
                if ansi[r][c]<1 and t[c]==0 and u[c][-1-i]=='0' and 1>min([ansi[l][c] for l in range(n) if l!=r]): #積で0の列の0を1にする。ただし他の要素に0がある場合のみ。
                    ansi[r][c]=1
                    ok=True
                    break
            if ok==False:
                print(-1)
                exit(0)
        if s[r]==0 and u[r][-i-1]=='0' and 0<min(ansi[r]): #積で0の行だが、まだ0がない
            ok=False
            for c in range(n):
                if ansi[r][c]==1 and t[c]==1 and u[c][-1-i]=='1' and 0<max([ansi[l][c] for l in range(n) if l!=r]): #和で1の列の1を0にする。ただし他の要素に1がある場合のみ。
                    ansi[r][c]=0
                    ok=True
                    break
            if ok==False:
                print(-1)
                exit(0)
    for c in range(n): #列に対する操作
        if t[c]==1 and v[c][-i-1]=='1' and 1>max([ansi[l][c] for l in range(n)]): #和で1の列だが、まだ1がない
            ok=False
            for r in range(n):
                if ansi[r][c]<1 and s[r]==0 and v[r][-1-i]=='0' and 1>min([ansi[r][l] for l in range(n) if l!=c]): #積で0の行の0を1にする。ただし他の要素に0がある場合のみ。
                    ansi[r][c]=1
                    ok=True
                    break
            if ok==False:
                print(-1)
                exit(0)
        if t[c]==0 and v[c][-i-1]=='0' and 0<min([ansi[l][c] for l in range(n)]): #積で0の列だが、まだ0がない
            ok=False
            for r in range(n):
                if ansi[r][c]==1 and s[c]==1 and v[c][-1-i]=='1' and 0<max([ansi[r][l] for l in range(n) if l!=c]): #和で1の行の1を0にする。ただし他の要素に1がある場合のみ。
                    ansi[r][c]=1
                    ok=True
                    break
            if ok==False:
                print(-1)
                exit(0)
    for r in range(n):
        for c in range(n):
            ans[r][c]+=pow(2,i)*max(0,ansi[r][c])
for a in ans:
    print(' '.join(map(str,a)))