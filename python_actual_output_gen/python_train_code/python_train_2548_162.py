n=int(input())
print(sum(sorted([int(i) for i in input().split()])[n:2*n]))