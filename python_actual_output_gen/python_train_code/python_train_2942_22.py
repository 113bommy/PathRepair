#
n=int(input())
a=list(map(int,input().split()))
a=sorted(a)
if [0]==a[-1]:
    print(-1)
else:
    print(*a)