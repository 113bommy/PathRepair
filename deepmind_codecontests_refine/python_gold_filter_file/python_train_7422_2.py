import sys
input=sys.stdin.readline

t = int(input())

for i in range(t):
    n=int(input())
    roads=list(input())
    ans=[]
    lefts=[0 for i in range(n+1)]
    rights=[0 for i in range(n+1)]

    if roads[0]=='L':
        lefts[1]=1
    if roads[n-1]=='R':
        rights[n-1]=1

    for i in range(2,n+1):
        if roads[i-1]=='L':
            if roads[i-2]=='L':
                lefts[i]=1
            else:
                lefts[i]=lefts[i-2]+2
    for i in range(n-2,-1,-1):
        if roads[i]=='R':
            if roads[i+1]=='R':
                rights[i]=1
            else:
                rights[i]=rights[i+2]+2
        

    for i in range(n+1):
        ans.append(str(lefts[i]+rights[i]+1))
    print(" ".join(ans))