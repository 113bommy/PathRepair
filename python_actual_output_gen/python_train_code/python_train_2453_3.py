# Surely we just traverse the whole thing first, looking for the connected parts of the graph
# And anything we bump into is simply re-used?
# By inspection, things in the same cycle have the same value - the cycle length

t = int(input())
for x in range(t):
    n = int(input())
    l1 = [int(x) for x in input().split()]
    # I think, we simply have two intermediary arrays - the one with the answers to clear and to store until we hit a cycle, the other to simply keep
    i=0
    
    ans = [0]*n

    visited=[]

    while i<len(l1):
        if l1[i]==i+1:
            ans[i]=1
            visited.append(i)

        elif l1[i] not in visited:
            j=i
            cycle=[]
            while j not in visited:
                cycle.append(j)
                visited.append(j)
                j = l1[j]-1

            for x in cycle:
                ans[x]=len(cycle)
            
        i+=1
    
    print(*ans)
    
