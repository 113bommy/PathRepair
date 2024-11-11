
def bidui():
    for i in range(n):
        for j in range(m):
            if mp[i][j]!=v[i][j]:
                return 0
    return 1

if __name__ == '__main__':
    n,m=map(int,input().strip().split())
    mp = []
    for i in range(n):
        tmp = input().strip().split()[0]
        mp.append(list(tmp))
    v = [['.']*m for i in range(n)]
    dx = [0,0,-1,-1,-1,1,1,1]
    dy = [-1,1,-1,0,1,-1,0,1]
    for i in range(n):
        for j in range(m):
            tag = 1
            for k in range(8):
                nx = i+dx[k]
                ny = j+dy[k]
                if nx<0:
                    tag=0
                    break
                if nx>=n:
                    tag=0
                    break
                if ny<0:
                    tag=0
                    break
                if ny>=m:
                    tag=0
                    break
                #print(nx,n,ny,m)
                if mp[nx][ny]!='#':
                    tag=0
                    break
            if tag==0:
                continue
            for k in range(8):
                nx = i+dx[k]
                ny = j+dy[k]
                v[nx][ny]='#'

    if bidui()==1:
        print('YES')
    else:
        print('N0')
                
