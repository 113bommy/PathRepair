N = int(input())
print(min([sum(list(map(int,input().split()))) for j in range(N)])