n = int(input())
L = [int(input()) for i in range(n)]

print(int(sum(L) - max(L)/2))