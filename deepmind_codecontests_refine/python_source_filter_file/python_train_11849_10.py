N = int(input())
S =list(input())
s = list(set(S))
m = 1
for i in range(len(s)):
    m *= (S.count(s[i]) + 1)
    
print((m - 1) % (10 ** 9 + 7)