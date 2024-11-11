for _ in range(int(input())):
    n,x=map(int,input().split())
    a=list(map(int,input().split()))
    arr=[x-a[i] for i in range(n)]
    if max(a)==min(a):
        print(0)
    elif sum(arr)==0 or x in a:
        print(1)
    else:
        print(2)