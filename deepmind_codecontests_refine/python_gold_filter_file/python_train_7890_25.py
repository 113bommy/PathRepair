import re

N = int(input())
S = str(input())
K = int(input())

print(re.sub(r'[^%s]'%S[K-1], '*', S))