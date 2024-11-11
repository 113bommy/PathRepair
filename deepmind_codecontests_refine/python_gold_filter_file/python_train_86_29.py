a=list(map(int,input().split()))
b=sorted(a)
print(['No','Yes'][b[2]==b[1]+b[0]])
