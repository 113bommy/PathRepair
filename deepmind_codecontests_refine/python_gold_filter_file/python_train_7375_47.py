n = int(input())
a = list(map(int,input().split()))
a.sort(reverse=True)
print(sum(a[1:3*n-n:2]))
