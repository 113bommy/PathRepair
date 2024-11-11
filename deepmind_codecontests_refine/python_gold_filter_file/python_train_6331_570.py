N = int(input())
pi = [int(input()) for _ in range(N)]
print(sum(pi)-max(pi)//2)