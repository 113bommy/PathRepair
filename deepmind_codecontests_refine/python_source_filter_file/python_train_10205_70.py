while True:
    x,y = map(int,input().split())
    if H==W==0:
        break;
    for i in range(x):
        print("#"*y)
    print()

