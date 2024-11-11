import sys
sys.setrecursionlimit(5000)

def detectGroup(parents,x):
    if parents[x]!=x:
        parents[x]=detectGroup(parents,parents[x])
        return parents[x]
    else:
        return x
    
N,M=map(int,input().split())
AB=[[int(x)-1 for x in input().split()] for i in range(M)][::-1]
parents=[i for i in range(N)]
groupsize=[1 for i in range(N)]
inconv=N*(N-1)/2
result = []
for i in range(M):
    result.append(str(int(inconv))+'\n')
    groupA=detectGroup(parents,AB[i][0])
    groupB=detectGroup(parents,AB[i][1])
    if groupA!=groupB:
        inconv-=groupsize[groupA]*groupsize[groupB]
        groupsize[groupA]+=groupsize[groupB]
    parents[groupB] = groupA
print("".join(result[::-1]))