for _ in range(int(input())):
    n=input()
    l=list(map(int , input().split()))
    p=set(map(int ,input().split()))
    if sorted(l) == l:
        print("Yes")
    else:
        if 1 in p and 0 in p:
            print("Yes")
        else:
            print("No")