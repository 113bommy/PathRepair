for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    # print(arr)
    s=sum(arr)
    arr.sort()
    if s==0 :
        print("NO")
    elif s>0:
        print("YES")
        print(arr[::-1])
    else:
        print("YES")
        print(arr)