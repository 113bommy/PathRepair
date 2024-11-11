n,m = input().split()
LR =  [list(map(int,input().split())) for i in range(int(m))]
s = max([i[0] for i in LR])
e = min([i[1] for i in LR])
print(max(e-s+1,0))