n=int(input())
s=sorted(list(map(int,input().split())))
if sum(s[:n])!=sum(s[n:2*n]):
    for i in s:
        print(i,end=" ")
else:
    print(-1)