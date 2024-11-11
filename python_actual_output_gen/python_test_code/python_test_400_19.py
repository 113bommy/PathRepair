n,m,k=map(int,input().split())
l=sorted(list(map(int,input().split())))
print((m//(k+1))*(k*l[-1]+l[-2])+l[-1]*m%(k+1))