nh,nr=map(int, input().split())
h=list(map(int, input().split()))
r=list(map(int, input().split()))
ps=[0]*nh
ps[0]=h[0]
psum=h[0]
for i in range(1,nh):
    ps[i]=ps[i-1]+h[i]
# print(*ps,end=' ')
ub=0
for i in range(nr):
    v=r[i]
    if(v<ps[0]+1):
        print(ub+1,v,sep=' ')
        # print()
    else:
        while(True):
            if(v<ps[ub]+1):
                print(ub+1,v-ps[ub-1],sep=' ')
                break
            else:
                ub+=1
                continue