n,d=map(int,input().split())
arr=[int(i) for i in input().split()]
m=int(input())
arr.sort()
if m>=n:
    print(sum(arr)-(m-n)*d)
elif m<n:
    print(sum(arr[:n+1]))