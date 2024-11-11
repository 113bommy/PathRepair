for _ in range(int(input())):
    n=int(input())
    s=0
    l=list(map(int,input().split()))
    for i in range(102):
        if i not in l:
            s=s+i
            break
    for i in range(102):
        if l.count(i)<2:
            s=s+i
            break
    print(s)    
            