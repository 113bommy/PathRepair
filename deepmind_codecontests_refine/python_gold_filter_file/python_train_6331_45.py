N = int(input())
PP = [int(input()) for _ in range(N)]
print(sum(PP)-max(PP)//2)