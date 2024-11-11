for _ in range(int(input())):
    n=int(input())
    l = [int(x) for x in input().split()]
    for i in range(n):
        if l[i]!=1:
            break
    if i%2==1:
        print("Second")
    else:
        print("First")