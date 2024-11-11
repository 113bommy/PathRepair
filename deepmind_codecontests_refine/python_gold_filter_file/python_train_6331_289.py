N = int(input())
p = [int(input()) for k in range(N)]
print(sum(p)-max(p)//2)