R = lambda:map(int,input().split())
n,m = R()
l =[i for i in sorted(R()) if i<=m]
print([m-len(l),m-len(l)+1][m in l])