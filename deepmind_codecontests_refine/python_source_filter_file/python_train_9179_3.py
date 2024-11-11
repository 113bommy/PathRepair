n = int(input())
s = list(input())
k = 0
for i in range(0, n, 2):
    if(s[i] == s[i+1] and s[i] == "a"):
        s[i + 1] = "b"
        k += 1
    elif(s[i] == s[i+1] and s[i] == "b"):
        s[i + 1] = "a"
        k += 1

print(k)
print(s)
