N=int(input())
triangle=[(i*(i-1))//2 for i in range(0,N+1)]
if not N in triangle:
    print('No')
else:
    print('Yes')
    k=triangle.index(N)
    print(k)
    count=0
    S=[[] for i in range(0,k)]
    for i in range(0,k):
        if i==0:
            S[i]=[j for j in range(1,k)]
            count=k-1
        else:
            for j in range(0,i):
                S[i].append(S[j][i-1])
            for j in range(0,k-1-i):
                S[i].append(count+1)
                count+=1
        print(k-1,*S[i])
