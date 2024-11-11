n = int(input())
l = sorted(list(map(int, input().split())),reverse=True)
print(sum(l[n:n*2]))