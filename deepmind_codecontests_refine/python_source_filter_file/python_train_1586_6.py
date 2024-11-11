# cook your dish here
t = int(input())
for t_case in range(t):
    (n,m) = map(int, input().split())
    N=list(map(int, input().split()))
    M=list(map(int, input().split()))
    D=set()
    L2=[False for i in range(n)]
    L1=L=[False for i1 in range(n)]
    L=[False for i2 in range(n)]
    L4=[False for i3 in range(n)]
    for x in M:
        #L[x-1]=True
        L2[x]=True
        L1[x-1]=True
        L4[x]=True
        L4[x-1]=True
    for h in range(n):
        if L1[h]==True and L2[h]==True:
            L[h]=True
    qw='YES'
    for j in range(n):
        if L4[j]==False:
            if j==0:
                if N[j]>min(N[j+1:]):
                    qw='NO'
                    break
            elif j==n-1:
                if min(N[:j])>N[j]:
                    qw='NO'
                    break
            if j!=0 and j!=n-1:
                if min(N[:j])>N[j] or N[j]>min(N[j+1:]):
                    qw='NO'
                    break
    #print(qw)
    if qw=='YES':
        #print(L1,L)
        for y in range(n):
            if L1[y]==True and L[y]==False and y!=0:
                if min(N[y:])<min(N[:y]):
                    qw = 'NO'
                    break
    #print(qw)            
    if qw=="YES":
        for y1 in range(n):
            if L2[y1]==True and L[y1]==False and y1!=n-1:
                if min(N[y1+1:])<min(N[:y1+1]):
                    qw = 'NO'
                    break
    
    print(qw)