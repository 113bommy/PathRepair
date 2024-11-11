s = input()
l = []
for i in range(len(s)-3):
    l.append(abs(int(s[i:i+3])-753))
print(min(l))