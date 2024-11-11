from os import sys
num = int(input())
vertices=[]
[vertices.append([]) for c in range(num+1)]
weightUnder=[-1]*(num+1)
visited = [-1]*(num+1)
sys.setrecursionlimit(100000)

def calculateWeight(i):
    totalWeightUnder=0
    visited[i]=1
    for (vert,weight) in vertices[i]:
        if visited[vert]==-1:
            totalWeightUnder+=weight+calculateWeight(vert)

    weightUnder[i]= totalWeightUnder
    return totalWeightUnder

def getSolution(i):
    visited[i]=1
    minValue = 2000000001
    for (vert,weight) in vertices[i]:
        if (visited[vert]==-1):
            newValue = weight+getSolution(vert)
            minValue = min((weightUnder[i]-weight-weightUnder[vert])*2+newValue,minValue)
    if minValue == 2000000001:
        return 0
    return minValue

def solve():
    global num
    for x in range(num-1):
        x,y,w = list(map(int, input().split()))
        vertices[x].append((y,w))
        vertices[y].append((x,w))
    calculateWeight(1)
    for i in range(num+1):
        visited[i]=-1 
    currentNode = 1
    print (getSolution(currentNode))

try:
    solve()
except Exception as e:
    print (e)