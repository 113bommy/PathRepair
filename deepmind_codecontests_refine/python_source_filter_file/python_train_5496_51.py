n = int(input())
dc=[list(map(int,input().split())) for i in range(n)]

sm=0
cnt=0
for tmp in dc:
    d,c=tmp
    cnt+=c
    sm+=d*c
print(cnt-1 + sm//10)