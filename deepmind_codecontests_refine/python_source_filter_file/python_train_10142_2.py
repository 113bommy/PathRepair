x=list(map(int,input().split()))
p=[0,0,0]
for i in range(1,7):
    if abs(x[0]-i)>(x[1]-i):
        p[0]+=1
    elif abs(x[0]-i)<(x[1]-i):
        p[2]+=1
    else : p[1]+=1
print(p)
    
