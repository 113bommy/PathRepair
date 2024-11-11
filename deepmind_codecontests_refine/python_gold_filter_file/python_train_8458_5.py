t=int(input())
for _ in range(t):
    n=int(input())
    list1=list(map(int,input().split()))
    set1=set()
    result=[]
    for i in list1:
        if i not in set1:
            result.append(i)
        set1.add(i)
    print(*result)