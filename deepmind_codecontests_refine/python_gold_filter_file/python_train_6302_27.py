n = int(input())
s = ""
z = 1
while len(s) < n:
    s += str(z)
    z += 1
print(s[n-1])
