N = int(input())
l = list(map(int,input().split()))
l.sort()
print(sum(l[1:]))