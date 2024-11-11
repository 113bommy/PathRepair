n=int(input())
a=list(map(int,input().split()))
a.sort()
l=a[-1]-a[0]+1
print(l-n)