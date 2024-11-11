for _ in range(int(input())):
    n,m,k=map(int,input().split())
    hr,vr=k,(m*n)//2 - k
    four=(n//2)*(m//2)
    mat=[[0 for i in range(m)] for j in range(n)]
    ans="YES"
    if m%2==0:
        if n%2!=0:
            hr-=(m//2)
            for i in range(0,m,2):
                if i==0 or mat[-1][i-1]=='b':
                   mat[-1][i]='a'
                   mat[-1][i+1]='a'
                else:
                    mat[-1][i]='b'
                    mat[-1][i+1]='b'
    else:
        if n%2==0:
            vr-=(n//2)
            for i in range(0,n,2):
                if i==0 or mat[i-1][-1]=='c':
                   mat[i][-1]='d'
                   mat[i+1][-1]='d'
                else:
                    mat[i][-1]='c'
                    mat[i+1][-1]='c'
    if vr>=0 and hr>=0:
        if hr%2!=0 :
            ans="NO"
    else:
        ans="NO"
    if ans=="YES":
        print(ans)
        for i in range(0,n-n%2,2):
            for j in range(0,m-m%2,2):
                if hr!=0:
                    if j==0 or mat[i][j-1]!='e':
                        mat[i][j]='e'
                        mat[i][j+1]='e'
                        mat[i+1][j]='f'
                        mat[i+1][j+1]='f'
                    else:
                        mat[i][j]='g'
                        mat[i][j+1]='g'
                        mat[i+1][j]='h'
                        mat[i+1][j+1]='h'
                    hr-=2
                else:
                    if i==0 or mat[i-1][j]!='i':
                        mat[i][j]='i'
                        mat[i+1][j]='i'
                        mat[i][j+1]='j'
                        mat[i+1][j+1]='j'
                    else:
                        mat[i][j]='k'
                        mat[i+1][j]='k'
                        mat[i][j+1]='l'
                        mat[i+1][j+1]='l'
                    vr-=2
        for i in range(n):
            for j in range(m):
                print(mat[i][j],end='')
            print('')

    else:
        print(ans)
    
        




