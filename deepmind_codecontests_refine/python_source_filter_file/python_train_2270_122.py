n, k = [int(x) for x in input().split()]
s = input()
print(s[:k-1]+s[k].lower()+s[k+1:])