def main():
    n,m=map(int,input().split())
    r=set()
    a,b=None,None
    for _ in range(n):
        a,b=map(int,input().split())
        r.add(a)
        r.add(b)
        for i in range(a,b+1):
            r.add(i)
    toprint=[]
    for i in range(1,b+1):
        if i not in r:
            toprint.append(i)
    print(len(toprint))
    print(*toprint)

main()
