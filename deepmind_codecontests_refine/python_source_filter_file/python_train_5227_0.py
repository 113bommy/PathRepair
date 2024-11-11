import sys
t=int(sys.stdin.readline())
def findopen(i,s,n):
    for j in range(i,n):
        if s[j]=='(':
            return j
def findclose(i,s,n):
    for j in range(i,n):
        if s[j]==')':
            return j
for _ in range(t):
    n,k=map(int,sys.stdin.readline().split())
    s=list(sys.stdin.readline()[:-1])
    #print(s,'s')
    ans=[]
    left,right,i=-1,-1,0
    i=0
    rem=n//2-(k-1)
    while k>1:
        a=findopen(i,s,n)
        #print(a,'a',i,'i',s,'s')
        if a!=i:
            ans.append([a+1,i+1])
            s[i],s[a]=s[a],s[i]
        b=findclose(i+1,s,n)
        if b!=i+1:
            ans.append([b+1,i+2])
            s[i+1],s[b]=s[b],s[i+1]
        k-=1
        i+=2
    #rem=n//2-(k)
    #print(rem,'rem')
    while rem>0:
        a=findopen(i,s,n)
        if a!=i:
            ans.append([a+1,i+1])
            s[i],s[a]=s[a],s[i]
        rem-=1
        i+=1
    #print(s,'s')
    m=len(ans)
    print(m)
    for i in range(m):
        print(*ans[i])
            
