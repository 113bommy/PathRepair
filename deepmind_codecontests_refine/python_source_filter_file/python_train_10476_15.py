s = list(input())
d = len(s)
count = 0

for i in range(1):
    for j in range(1, d-1):
        for k in range(2, d):
            if s[i] == "Q" and s[j] == "A" and s[k] == "Q":
                count += 1

print(count)
