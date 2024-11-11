n,m=sorted(map(int,input().split()))
print(~1&n*m-2*{1:1<m%6<5,2:{2:2,3:1,7:2}.get(m,0)}.get(n,0))