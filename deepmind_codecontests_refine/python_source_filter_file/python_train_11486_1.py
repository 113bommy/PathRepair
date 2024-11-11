import sys
input = sys.stdin.readline
from operator import itemgetter

n,k=map(int,input().split())

if n%2==1 and k%2==0:
    print(-1,flush=True)
    exit()
    
if k==n-1:
    ANS=0
    for i in range(n):
        L=["?"]
        for j in range(n):
            if i==j:
                continue
            L.append(j+1)
        print(*L,flush=True)
        ANS^=int(input())
    print("!",ANS,flush=True)
    exit()

for i in range(n,10**9,2):
    if i%k==0:

        ind=0
        X=[0]*n
        while i:
            if X[ind]==0:
                X[ind]+=1
                i-=1
                ind=(ind+1)%n

            elif X[ind]>=1:
                X[ind]+=2
                i-=2
                ind=(ind+1)%n
                
        XI=[]
        for j in range(n):
            XI.append([X[j],j])

        ANS=[]
        flag=1
        for j in range(sum(X)//k):
            XI.sort(key=itemgetter(0),reverse=True)

            Y=["?"]
            for l in range(k):
                if XI[l][0]>=1:
                    XI[l][0]-=1
                    Y.append(XI[l][1]+1)
                else:
                    flag=0
                    break
            ANS.append(Y)
            #print(ANS)
            if flag==0:
                break
        if flag==0:
            continue
        else:
            break

XX=0
for ans in ANS:
    print(*ans,flush=True)
    #XX^=int(input())

print("!",flush=True)
print(XX,flush=True)
    
                
            
