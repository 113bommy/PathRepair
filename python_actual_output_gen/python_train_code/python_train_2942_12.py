n=int(input())
l=list(map(int, input().split()))
l.sort()
if(sum(l[:n])!=sum(l[n:])):
    for i in range(len(l)):
        print(l[i],end='')
    print()
else:
    print(-1)