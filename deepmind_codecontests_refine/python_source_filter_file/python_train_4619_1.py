l = [input().split() for _ in range(int(input()))]
print(sum(j.count('1') >= 2) for j in l)