n = int(input())
s = input()
print(s if len(s) <= n else s[:n] + '...')