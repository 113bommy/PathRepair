n = int(input())
print(sum(sorted([int(i) for i in input().split()], reverse=True)[1:n*2:2]))