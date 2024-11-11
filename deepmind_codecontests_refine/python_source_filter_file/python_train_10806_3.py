input()
v=list(map(int,input().split())
c=list(map(int,input().split())
a=[max(0,i-j) for i,j in zip(v,c)]
print(sum(a))