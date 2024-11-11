s = input().split()
name = s[0]
surname = s[1]
i = 1
j = 0
while i < len(name) and j < len(surname) and name[i] <= surname[j]:
    i += 1
print(name[0:i] + surname[0:j+1])
