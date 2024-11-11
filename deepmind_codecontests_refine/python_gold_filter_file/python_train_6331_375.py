n = int(input())
l = [int(input()) for _ in [0]*n]

print(sum(l)-max(l)//2)
