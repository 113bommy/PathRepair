
n,m=map(int,input().split())
L=[]
for _ in range(n):
    L.append(list(input()))
#print(L)
visited=set()
islands=[]

island=1
for i in range(n):
    for j in range(m):
        if (i,j) not in visited and L[i][j]=="#":
            islands.append(1)
            stack=[(i,j)]
            while stack:
                I,J=stack.pop()
                visited.add((I,J))
                p=[(1,0),(-1,0),(0,1),(0,-1)]
                for t in p:
                    g,h=I+t[0],J+t[1]
                    if (g,h) not in visited and 0<=g<n and 0<=h<m and L[g][h]=="#":
                        stack.append((g,h))
            
            island+=1
def checkline(arr):

    va=-1
    for i in range(len(arr)):
        if va==2 and arr[i]=="#":
            return False
        elif va==1 and arr[i]==".":
            va=2
        elif arr[i]=="#":
            va=1
    return True
ans=0       
for i in range(n):
    if not checkline(L[i]):
        ans=-1
        break
for j in range(m):
    B=[]
    for i in range(n):
        B.append(L[i][j])
    if not checkline(B):
        ans=-1
        break
check1,check2=0,0
for i in range(n):
    if L[i].count(".")==len(L[i]):
        check1=1
        break
for j in range(m):
    B=[]
    for i in range(n):
        B.append(L[i][j])
    if B.count(".")==len(B):
        check2=1
        break
print(check1,check2)
if ans!=-1:
    if (check1,check2)==(1,0) or (check1,check2)==(0,1) :
        print(-1)
    else:
        print(len(islands))
##    p=""
##    if L==[["."],["#"]]:
##        print(-1)
##    elif L==[["#"]]:
##        print(1)
##    elif L==[["."]]:
##        print(0)
##    elif n==1 or m==1:
##        print(sdada)
##        for i in range(n):
##            for j in range(m):
##                p+=L[i][j]
##        if 0<p.count("#")<len(p):
##            print(-1)
##        elif p.count("#")==len(p):
##            print(1)
##        else:
##            print(0)
##    else:      
##        print(len(islands))
else:
    print(-1)
