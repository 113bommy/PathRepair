n, k = map(int, input().split())
l = sorted(map(int, input().split()))
if(k == n):
    print(l[-1])
elif(k == 0):
    if(l[0] == 1):
        print(-1)
    else:
        print(l[0]-1)
else:
    if(l[k-1] == l[k]):
        print(-1)
    else:
        print(l[k-1])
