import sys
input = sys.stdin.readline
q=int(input())
for i in range(q):
    h,n=map(int,input().split())
    #switch=[0]*(h+1)
    l=list(int(i) for i in input().split())
    l.append(0)
    #print(l)
    #print(switch)
    level=1
    crystal=0
    while level<n:
        if l[level+1]==(l[level]-1):
            level+=2
        else:
            crystal+=1
            level+=1
    print(crystal)
                
