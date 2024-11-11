k = int(input())
s = sorted(input())
x = s[::k]*k
print((-1,x)[sorted(x) == s])

