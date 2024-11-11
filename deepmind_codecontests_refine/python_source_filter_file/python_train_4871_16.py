H,W = map(int,input().split())
if(min(H,W) == 1):
    print(0)
    exit()
print((H*W+((H*W)%2))//2)