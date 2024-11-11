for i in range(int(input())):
    a=int(input())
    b=list(map(int,input().split()))
    print("NYOE S"[len(b)==len(set(b))::2])