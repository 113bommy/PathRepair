import sys
input=sys.stdin.readline
from collections import deque

def main():
    n=int(input())
    Edges=[[] for _ in range(n)]
    for _ in range(n-1):
        a,b=map(int,input().split())
        a-=1; b-=1
        Edges[a].append(b)
        Edges[b].append(a)
    Depth=[-1]*n
    Depth[0]=0
    q=deque()
    q.append(0)
    while q:
        fr=q.popleft()
        for to in Edges[fr]:
            if Depth[to]==-1:
                Depth[to]=Depth[fr]+1
                q.append(to)
    Group=[[] for _ in range(2)]
    for i in range(n):
        Group[Depth[i]%2].append(i)
    l_even,l_odd=len(Group[0]),len(Group[1])
    Ans=[0]*n
    Used=[False]*(n+1)
    if l_even<=l_odd:
        if l_even<n//3:
            tmp_3=3;tmp_others=1
            for i in Group[0]:
                Ans[i]=tmp_3
                Used[tmp_3]=True
                tmp_3+=3
            for i in Group[1]:
                while Used[tmp_others]:
                    tmp_others+=1
                Ans[i]=tmp_others
                Used[tmp_others]=True
            return Ans
    else:
        if l_odd<n//3:
            tmp_3=3;tmp_others=1
            for i in Group[1]:
                Ans[i]=tmp_3
                Used[tmp_3]=True
                tmp_3+=3
            for i in Group[0]:
                while Used[tmp_others]:
                    tmp_others+=1
                Ans[i]=tmp_others
                Used[tmp_others]=True
            return Ans
    tmp_even=1;tmp_odd=2;tmp_others=3
    for i in Group[0]:
        if tmp_even<=n:
            Ans[i]=tmp_even
            tmp_even+=3
        else:
            Ans[i]=tmp_others
            tmp_others+=3
    for i in Group[1]:
        if tmp_odd<=n:
            Ans[i]=tmp_odd
            tmp_odd+=3
        else:
            Ans[i]=tmp_others
            tmp_others+=3
    return Ans
    
if __name__=='__main__':
    Ans=main()
    print(*Ans)