a=int(input())
for _ in range(a):
    b,c=map(int,input().split())
    d=input()
    ans=0
    for i in range(c//2):
        now=i
        data={}
        while now<b:
            if d[now] not in data:
                data[d[now]]=0
            data[d[now]]+=1
            now+=c
        now=c-i-1
        while now<b:
            if d[now] not in data:
                data[d[now]]=0
            data[d[now]]+=1
            now+=c
        ans+=max(data.values())
    if c%2==1:
        now=c//2
        data={}
        while now<b:
            if d[now] not in data:
                data[d[now]]=0
            data[d[now]]+=1
            now+=c
        ans+=max(data.values())
    print(b-ans)