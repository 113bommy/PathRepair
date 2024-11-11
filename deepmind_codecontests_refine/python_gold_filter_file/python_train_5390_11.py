n = int(input())
c = input()

a = c.count('R')
b = c[:a].count('W')
print(b)