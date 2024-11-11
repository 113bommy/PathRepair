k = int(input())
s = str(input())
n = len(s) - k
print(s[:-k-1]+'...' if n>0 else s)