n,m=sorted(map(int,input().split()))
print(~1&n*m-{1:2*(1<m%6<5),2:{2:4,3:2,7:2}.get(m,0)}.get(n,0))