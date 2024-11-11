n = int(input())
s = input()
w = s.count('W')
print(s[-w:].count('R'))