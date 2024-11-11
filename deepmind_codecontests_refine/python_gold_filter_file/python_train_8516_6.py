N=int(input())
S=input()
Q=int(input())
K=[int(i) for i in input().split()]
def f(k):
    num=0
    L=[0,0,0]
    for i in range(N):
        if i-k>=0:
            if S[i-k]=='D':
                L[0]-=1
                L[2]-=L[1]
            elif S[i-k]=='M':
                L[1]-=1
        if S[i]=='D':
            L[0]+=1
        elif S[i]=='M':
            L[1]+=1
            L[2]+=L[0]
        elif S[i]=='C':
            num+=L[2]
        #print(i,':',L,':',num)
    return num
for k in K:
    print(f(k))