s = input()
x = []
for i in range(len(s)-2):
    x.append(abs(int(s[i:i+3])-753))
print(min(x))