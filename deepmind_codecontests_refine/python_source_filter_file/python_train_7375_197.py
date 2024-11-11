n = int(input())
l = list(map(int, input().split()))
l.sort()
print(sum(l[n:2*n]))