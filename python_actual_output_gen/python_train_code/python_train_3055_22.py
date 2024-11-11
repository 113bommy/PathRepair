n  = int(input())
s = input()
out = 1
for i in range(n-1):
    if s[i] == s[i+1] :
        out += 1
print(out)
    