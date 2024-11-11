n=int(input())
a=[*map(int,input().split())]

print(n-a.count(max(a))-a.count(min(a)))