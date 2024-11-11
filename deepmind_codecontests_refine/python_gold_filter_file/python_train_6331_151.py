s = int(input())
p = [int(input()) for i in range(s)]
print(sum(p) - max(p) // 2)