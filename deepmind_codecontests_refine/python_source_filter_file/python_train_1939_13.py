N=int(input())
N*=2
W=[]
W=input().split()
for i in range(len(W)):
    W[i]=int(W[i])
W.sort()

instab=1

for i in range(0,N):
    for j in range(i+1,N):
        a=[]
        for z in range(N):
            if z!=i and z!=j:
                a.append(W[z])
        total=0
        for k in range(0,N-2,2):
            total+=a[k+1]-a[k]
        instab=min(instab,total)
print(instab)



