a=list(map(int,input().split()))
b=sorted(a)
print(['NO','YES'][b[2]==b[1]+b[0]])
