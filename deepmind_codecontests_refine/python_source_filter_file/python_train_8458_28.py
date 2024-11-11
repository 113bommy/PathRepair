for _ in range(int(input())):
    n=int(input())
    li=list(map(int,input().split()))
    s=[]
    for i in li:
        if i not in s:
            s.append(i)
    print(s)