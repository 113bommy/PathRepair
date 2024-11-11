n = int(input())
a = list(map(int,input().split()))
print(min(a[-1]-a[1],a[-2]-a[0]))