n = int(input())
a = list(map(int,input().split()))
print((sum(sorted(a)[n:n*2])))