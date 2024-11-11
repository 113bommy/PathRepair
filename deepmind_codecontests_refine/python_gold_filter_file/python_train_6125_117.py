a,b,c,d=map(int,input().split())
print([["Balanced","Left"][a+b>c+d],"Right"][a+b<c+d])