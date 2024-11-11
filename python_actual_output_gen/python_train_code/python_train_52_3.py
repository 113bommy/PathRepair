s = input()
k = int(input())
result = ''.join(c.upper()
                 if ord(c) < k+97
                 else c.lower()
                 for c in s)
print(result)
