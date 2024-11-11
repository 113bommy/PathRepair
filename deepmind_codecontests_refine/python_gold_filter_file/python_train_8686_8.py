n,m=map(int,input().split())
mat=[]
for i in range(n):
    s=input()
    mat.append(s)
d=1
for i in range(n):
    c=1
    for j in range(m):
        if mat[i][j]=='-':
            print('-',end='')
        elif d==1:
            if c%2==0:
                print('B',end="")
            else:
                print('W',end="")
        else:
            if c%2==0:
                print('W',end="")
            else:
                print('B',end="")
        c+=1
    d=d^1
    print()        
