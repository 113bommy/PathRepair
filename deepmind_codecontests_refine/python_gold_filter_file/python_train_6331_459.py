n = int(input())
x = [int(input()) for i in range(n)]

print(sum(x)-max(x)//2)