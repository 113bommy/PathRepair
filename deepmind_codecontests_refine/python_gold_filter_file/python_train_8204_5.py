n = int(input())
s = input()
a = 0
for i in range(1,n+1):
    a = max(a,len(set(s[:i]) & set(s[i:])))

print(a)