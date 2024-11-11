import sys

dct = {"b": "d", "d", "b", "p": "q", "q": "p"}
S = sys.stdin.readline().strip()
rev = ""
for s in S[::-1]:
    rev += dct[s]

if rev == S:
    print("Yes")
else:
    print("No")