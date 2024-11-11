s = str(input())
k = int(input())
l = []
for i in range(len(s)):
    for j in range(k+1):
        l.append(s[i:i+j])

print(sorted(set(l))[k-1])