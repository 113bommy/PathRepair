t=int(input())
import heapq
for _ in range(t):
    n=int(input())
    L=[];R=[]
    ans=0
    for _ in range(n):
        ki,li,ri = map(int, input().split())
        dif=li-ri
        if dif>=0:
            L.append((ki-1,dif))
            ans+=ri
        else:
            R.append((n-ki-1,-dif))
            ans+=li
    L.sort();R.sort()
    hL=[]
    hR=[]
    for i in range(len(L)):
        if L[i][0]>=len(hL):
            heapq.heappush(hL,L[i][1])
        elif L[i][0]==len(hL):
            heapq.heappushpop(hL,L[i][1])
    for i in range(len(R)):
        if R[i][0]>=len(hR):
            heapq.heappush(hR,R[i][1])
        elif L[i][0]==len(hR):
            heapq.heappushpop(hR,R[i][1])
    print(ans+sum(hL)+sum(hR))        
    
    