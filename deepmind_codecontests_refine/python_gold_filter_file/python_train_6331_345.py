n = int(input())
ps = [int(input()) for i in range(n)]
print(sum(ps) - max(ps)//2)