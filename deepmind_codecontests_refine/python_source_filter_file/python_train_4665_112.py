a=int(input())
s=list(map(int,input().split()))
s.sort()
print(s[a/2]-a[a/2-1])