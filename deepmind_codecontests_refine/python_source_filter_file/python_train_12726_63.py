for _ in range(int(input())):
       n,m = map(int,input().split())
       print([[m,0][n<2],2*m][m>2])
       