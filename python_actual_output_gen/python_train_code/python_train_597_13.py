for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    count=0
    min=a[n-1]
    for i in range(n-1):
        if a[(n-2)-i] > min :
            count+=1
        if a[(n-1)-i]<min:
            min=a[(n-2)-i]
    print(count) 