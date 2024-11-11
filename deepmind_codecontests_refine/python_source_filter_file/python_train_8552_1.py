n = int(input())
l = list(map(int,input().split()))
if len(set(l))==1:
    print(-1)
else:
    print(sorted(l))