import sys

input=sys.stdin.readline

def main():
    N,M=map(int,input().split())
    s=input()
    dic={"A":[0 for i in range(N)],"B":[0 for i in range(N)]}
    edge=[[] for i in range(N)]

    for i in range(M):
        a,b=map(int,input().split())
        a-=1;b-=1
        edge[a].append(b)
        edge[b].append(a)
        dic[s[a]][b]+=1
        dic[s[b]][a]+=1

    que=set([])
    check=0
    for i in range(N):
        if dic["A"][i]==0 or dic["B"][i]==0:
            que.add(i)
            dic["A"][v]=float("inf")
            dic["B"][v]=float("inf")

    while que:
        v=que.pop()
        check+=v+1
        for nv in edge[v]:
            dic[s[v]][nv]-=1
            if dic["A"][nv]==0 or dic["B"][nv]==0:
                dic["A"][v]=float("inf")
                dic["B"][v]=float("inf")
                que.add(nv)

    if check==N*(N+1)//2:
        print("No")
    else:
        print("Yes")

if __name__=="__main__":
    main()