def solve():
    n=int(input())
    a=[]
    ap=a.append
    k=0
    for s in map(set,input().split()):
        if not(s in a):
            ap(s)
    print(len(s))
solve()