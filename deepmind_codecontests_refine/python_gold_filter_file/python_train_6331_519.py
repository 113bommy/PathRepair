n = int(input())
N = [int(input()) for i in range(n)]

print(int(sum(N) - max(N)/2))