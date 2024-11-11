while True:

    W,H = map(int,input().split())
    if W==0 & H==0:
        break
    print("#"*H)
    for i in range(1,W-1):
        print("#"+"."*(H-2)+"#")
    print("#"*H)
    print(\n)