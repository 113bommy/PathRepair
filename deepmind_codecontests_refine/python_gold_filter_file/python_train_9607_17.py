'''

PROBLEM C


5
2 2
10
11
3 3
011
101
110
4 4
1111
0110
0110
1111
5 5
01011
11001
00010
11011
10000
2 3
011
101




'''



n=int(input())
for i in range(0,n):
    L=[]
    Q=[]
    W=[]
    S=[]
    D=[]
    ans=[]
    o=input().rstrip().split(' ')
    for j in range(0,int(o[0])):
        p=input().rstrip()
        p=list(p)
        L.append(p)
    # print(L)
    r=int(o[0])
    c=int(o[1])
    for j in range(0,r-1):
        for k in range(0,c-1):
            A=L[j][k:k+2]
            B=L[j+1][k:k+2]
            # print(A)
            # print(B)
            C=A.count('0') + B.count('0')
            E=[] # index of 0
            R=[] # index of 1
            for O in range(0,len(A)):
                if A[O]=='0':
                    E.append(j)
                    E.append(k+O)
                else:
                    R.append(j)
                    R.append(k+O)
            for O in range(0,len(B)):
                if B[O]=='0':
                    E.append(j+1)
                    E.append(k+O)
                else:
                    R.append(j+1)
                    R.append(k+O)    
            # print(E,R,C)
            if C==4:
                continue;
            elif C==0:
                ans.append(R[0])
                ans.append(R[1])
                ans.append(R[2])
                ans.append(R[3])                
                ans.append(R[4])
                ans.append(R[5])
                
                
                ans.append(R[0])
                ans.append(R[1])
                ans.append(R[2])
                ans.append(R[3])
                ans.append(R[6])
                ans.append(R[7])
                
                ans.append(R[0])
                ans.append(R[1])
                ans.append(R[4])
                ans.append(R[5])                
                ans.append(R[6])
                ans.append(R[7])
                
                ans.append(R[4])
                ans.append(R[5])                
                ans.append(R[6])
                ans.append(R[7])
                ans.append(R[2])
                ans.append(R[3]) 
                
                for O in range(k,k+2):
                    L[j][O]=str(0);
                    L[j+1][O]=str(0);                
                
                
            elif C==1:
                for O in range(0,len(R)):
                    ans.append(R[O])
                for O in range(k,k+2):
                    L[j][O]=str(0);
                    L[j+1][O]=str(0);
            elif C==2:
                for O in range(0,len(E)):
                    ans.append(E[O])
                ans.append(R[0])
                ans.append(R[1])
                for O in range(0,len(E)):
                    ans.append(E[O])
                ans.append(R[2])
                ans.append(R[3])
                for O in range(k,k+2):
                    L[j][O]=str(0);
                    L[j+1][O]=str(0);
            else:
                ans.append(E[0])
                ans.append(E[1])
                ans.append(E[2])
                ans.append(E[3])
                ans.append(R[0])
                ans.append(R[1])
                ans.append(R[0])
                ans.append(R[1])
                ans.append(E[4])
                ans.append(E[5])            
                ans.append(E[0])
                ans.append(E[1])
                ans.append(E[2])
                ans.append(E[3])
                ans.append(E[4])
                ans.append(E[5])   
                ans.append(R[0])
                ans.append(R[1])
                for O in range(k,k+2):
                    L[j][O]=str(0);
                    L[j+1][O]=str(0);
    print(len(ans)//6)
    for i in range(0,len(ans),6):
        print(ans[i]+1,end=' ')
        print(ans[i+1]+1,end=' ')
        print(ans[i+2]+1,end=' ')
        print(ans[i+3]+1,end=' ') 
        print(ans[i+4]+1,end=' ')
        print(ans[i+5]+1)        