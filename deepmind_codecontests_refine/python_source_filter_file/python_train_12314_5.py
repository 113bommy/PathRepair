for _ in [0]*int(input()):
    n = int(input())
    s = set(map(int,input().split()))
    print(["NO","YES"][len(s)==n])