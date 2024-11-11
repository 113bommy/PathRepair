k = int(input())
s = str(input())
n = len(s) - k
print(s[:k]+'...' if n>0 else s)