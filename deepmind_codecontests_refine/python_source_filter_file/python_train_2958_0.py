n,m=map(int,input().split())
R=list(map(int,input().split()))
W=list(map(int,input().split()))
R.sort()
W.sort()
if max(R)<min(W):
    for i in R:
        if i*2<max(R):
            print(max(R))
            break
    else:
        for i in R:
            if max(R)<i*2<min(W):
                print(i*2)
                break
        else:
            print(-1)
else:
    print(-1)