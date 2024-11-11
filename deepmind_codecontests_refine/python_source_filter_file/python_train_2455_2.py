n=int(input())
lst=[int(i) for i in input().split()]
if n==1:
    print(lst[0])
else:
    lst.sort()
    if n%2==0:
        k=n//2
        d=k-1
        print((lst[k]+lst[d])//2)
    else:
        print(lst[(n//2)-1])
