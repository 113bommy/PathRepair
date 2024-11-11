for i in range(int(input())):
    n=int(input())
    list1=list(map(int,list(input())))
    count=0
    for j in range(n-1):
        if list1[j]==0:
            count+=1
    print(sum(list1)+count)