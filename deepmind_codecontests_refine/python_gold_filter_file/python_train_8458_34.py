for _ in range (int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=[]
    for i in a:
        if i not in b:
            b.append(i)
            for j in range (a.count(i)//2):
                print(i,end=" ")
    print() 