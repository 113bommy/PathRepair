x = int(input())
s = x // 11
a = x % 11
print(s*2+2) if a > 6 else print(s*2+1)