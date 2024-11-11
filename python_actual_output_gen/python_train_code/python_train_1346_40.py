n,m=map(int,input().split())
for i in range(n):
    print(['*'*m,'.'*(m-1)+'*','*'*m,'*'+'.'*(m-1)][i%4])