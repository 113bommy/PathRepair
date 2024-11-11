n=int(input())
a=list(map(int,input().split()))
print(*(a[-1:0:-2]+a[::2]))