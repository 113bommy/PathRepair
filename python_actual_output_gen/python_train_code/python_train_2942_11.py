n=int(input())
s=sorted(list(map(int,input().split())))
if sum(s[:n+1])!=sum(s[n:2]):
    for i in s:
        print(i,end=" ")
else:
    print(-1)