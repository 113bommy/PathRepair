t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    if a.count(1)==n:
        if n%2==0:
            print("Second")
        else:
            print("First")
    else:
        c = 0
        for i in range(n-1):
            if a[i]!=1:
                c = i
                break
        if c%2==1:
            print("Second")
        else:
            print("First")