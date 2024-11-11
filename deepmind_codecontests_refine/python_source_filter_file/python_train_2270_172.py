n,k = map(int,inoput().split())
s = input()

print(s[:k-1]+s[k-1].lower+s[k:])