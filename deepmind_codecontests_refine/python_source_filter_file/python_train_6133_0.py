while(1):
    m=int(input())
    if m==0:    break
    #root, before, next, top, rank
    A=[[i for i in range(m+1)],[0 for i in range(m+1)],[0 for i in range(m+1)],[i for i in range(m+1)],[1 for i in range(m+1)]]
    
    while(1):
        I,J=map(int, input().split())
        if I==0:    break
        if I==J:
            pass
        else:
            srcroot=A[0][I]
            dstroot=A[0][J]
            srcrank=A[4][I]
            dstrank=A[4][J]
            if srcroot==dstroot and srcrank>dstrank:
                pass
            elif A[1][I]==0 and J==0:
                pass
            else:
                k=I
                while(A[2][k]!=0):
                    A[2][k],k=0,A[2][k]
                    if J==k: dstroot=J
                    A[0][k]=k
                    A[1][k]=0
                    A[3][k]=k
                    A[4][k]=1
                A[3][srcroot]=A[1][I]
                prevtop=A[3][dstroot]
                A[3][dstroot]=I
                A[0][I]=dstroot
                A[1][I]=prevtop
                A[2][I]=0
                A[3][I]=I
                A[4][I]=A[4][prevtop]+1
                A[2][prevtop]=I
                if J==0:
                    A[0][I]=I
                    A[1][I]=0
                    A[2][I]=0
                    A[3][I]=I
                    A[4][I]=1
                    
    ans=[0 for x in range(m+1)]
    for i in range(1,m+1):
        root=A[0][i]
        rank=A[4][i]
        ans[root]=max(ans[root], rank)
    ans=sorted(ans)
    #print(ans)
    print(A)
    for a in ans:
        if a!=0: print (a)
    print("end")
