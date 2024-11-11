n=int(input())
segs=[]
for i in range(n):
    a,b=map(int,input().split())
    segs.append([a,b,i])
segs.sort(key=lambda x:[x[0],-x[1]])
for i in range(1,n):
    if segs[i][1]<=segs[0][1]:
        print(segs[i][2]+1,segs[0][2]+1)
        exit()
segs.sort(key=lambda x:[-x[1],x[0]])
for i in range(1,n):
    if segs[i][0]>=segs[0][0]:
        print(segs[i][2]+1,segs[0][2]+1)
        exit()
print('-1 -1')