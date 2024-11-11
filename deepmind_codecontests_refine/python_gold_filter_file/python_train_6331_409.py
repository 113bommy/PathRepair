N = int(input())
p = [int(input()) for i in range(N)]

print(int(sum(p)-max(p)//2))