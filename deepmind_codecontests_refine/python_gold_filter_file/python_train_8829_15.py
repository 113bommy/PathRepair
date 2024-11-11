n = int(input())
a = list(map(int,input().split()))
b = sorted([x-i-1 for x,i in zip(a,range(n))])
print(sum([abs(x-b[n//2]) for x in b]))