k = int(input())
s = input()

if len(s)<=k:
    print(k)
else:
    print(s[:k]+'...')