n=int(input())
a=list(map(int, input().split()))
a.sort()

b=a[n:-n]
print(sum(b))