n  = int(input())
s = input()
out = 0
for i in range(n-1):
    if s[i] == s[i+1] :
        out += 1
print(out)
    