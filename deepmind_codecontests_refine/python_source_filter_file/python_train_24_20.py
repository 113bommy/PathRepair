def bad_triangle(arr,n):
    s=arr[0]+arr[1]
    if s<arr[n-1]:
        print(1,2,n)
    else:
        print(-1)
t=int(input())
for i in range(t):
    n=int(input())
    li=[int(x) for x in input().split()]
    bad_triangle(li,n)   