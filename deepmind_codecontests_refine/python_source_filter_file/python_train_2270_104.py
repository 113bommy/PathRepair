n, k = list(map(int, input().split()))
s = input()
print(s[:k-1]+s[k].lower()+s[k:])
