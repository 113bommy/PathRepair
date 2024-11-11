n=int(input())
for c in input():print(chr(64+(ord(c)-64+n)%26),end="")