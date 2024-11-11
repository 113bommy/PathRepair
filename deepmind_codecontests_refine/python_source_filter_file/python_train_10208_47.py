while True:

    W,H = tuple(map(int,input().split()))
    if W==0 & H==0:
        break
    for i in range(W):
        print("#"*H)
    |