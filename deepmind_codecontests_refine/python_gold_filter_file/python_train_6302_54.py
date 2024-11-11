n = int(input())
s = ""
k = 1
while len(s) < n:
    s += str(k)
    k += 1
print(s[n - 1])