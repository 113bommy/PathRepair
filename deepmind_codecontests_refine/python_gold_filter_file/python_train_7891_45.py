s = input()
m=[]
for i in range(len(s)-2):
    m.append(abs(int(s[i:i+3])-753))
print(min(m))


