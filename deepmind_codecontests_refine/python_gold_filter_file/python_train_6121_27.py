n = int(input())
a = list(map(int, input().split()))
l = [0]*n
for i in range(0,n):
    l[a[i]-1]=i+1
print(*l)