n = int(input())
print(sum(sorted([int(i) for i in input().split()], reverse=True)[n:n*2]))