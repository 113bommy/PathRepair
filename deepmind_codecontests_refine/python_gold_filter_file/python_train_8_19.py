N = int(input())
s = input()
eights = s.count("8")
m = len(s) // 11

print(min(eights, m))