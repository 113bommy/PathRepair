n,k = map(int,input().split())
s = input()
t = s.lower()
print(s[:(k-2)] + t[k-1] + s[k:])
