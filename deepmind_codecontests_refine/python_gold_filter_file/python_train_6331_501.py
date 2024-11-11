a = int(input())
b = [int(input()) for _ in range(a)]
print(sum(b) - max(b)//2)