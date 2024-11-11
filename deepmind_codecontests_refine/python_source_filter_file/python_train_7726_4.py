from math import log
for _ in range(int(input())):
    n,m=map(int,input().split())
    a=[int(i) for i in input().split()]
    if sum(a)<n:
        print(-1)
        continue
    maxx=int(log(max(a),2))
    b=[0]*(maxx+1)
    for i in a:
        b[int(log(i,2))]+=1
    bina=[int(i) for i in bin(n)[2:]]
    bina.reverse()
    ans=0
    for i in range(len(bina)):
        if b[i]>=bina[i]:
            b[i]-=bina[i]
            if i+1<len(b): b[i+1]+=b[i]//2
            else: b.append(b[i]//2)
            b[i]=0
        else:
            b[i]=2
            for j in range(i+1,len(b)):
                if b[j]==1:
                    b[j]=0
                    ans+=j-i
                    break
                else: b[j]=1
            if b[i]>=bina[i]:
                b[i]-=bina[i]
                if i+1<len(b): b[i+1]+=b[i]//2
                else: b.append(b[i]//2)
                b[i]=0        
    print(ans)                       
    