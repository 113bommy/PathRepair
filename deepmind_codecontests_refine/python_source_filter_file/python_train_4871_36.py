H, W = map(int, input().split())

if (H ==1)or(W==1):
    print(0)
else:
    print(H*W//2)