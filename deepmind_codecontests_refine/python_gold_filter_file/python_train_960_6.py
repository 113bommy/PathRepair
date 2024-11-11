import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)

def getCounts(r): #return counts up to r
    nCycles=r//cycleLength
    remainder=r-nCycles*cycleLength
    return nCycles*tot+cycleCounts[remainder]

t=int(input())
for _ in range(t):
    a,b,q=[int(x) for x in input().split()]
    cycleLength=a*b
    cycleCounts=[0]*(cycleLength)
    tot=0
    for x in range(cycleLength):
        if (x%a)%b!=(x%b)%a:
            tot+=1
        cycleCounts[x]=tot
    
    ans=[]
    for __ in range(q):
        l,r=[int(x) for x in input().split()]
        ans.append(getCounts(r)-getCounts(l-1))
    print(' '.join([str(x) for x in ans]))