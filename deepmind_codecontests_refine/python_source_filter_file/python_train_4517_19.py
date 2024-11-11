s = input().split()
n = int(s[0])
k = int(s[1])

out = ""
for i in reversed(range(1, k+1)):
    out += str(i) + " "
for i in range(k+1, n+1):
    out += str(i) + " "
    
print(out.strip())