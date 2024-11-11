n,k = map(int,input().split())
s = input()
t = s[k-1].lower()
print(s[:(k-2)] + t + s[k:])
