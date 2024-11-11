k = int(input())
s = input()
print(s if len(s) <= k else s[0:k:]+'...')