n = int(input())
s = input()
li = []
a = s.count("E")
li.append(a)

for i in range(n-1):
    if s[i] == "E" and s[i+1] == "E":
        a -= 1
        li.append(a)
    elif s[i] == "W" and s[i+1] == "W":
        a += 1
        li.append(a)
print(min(li))
