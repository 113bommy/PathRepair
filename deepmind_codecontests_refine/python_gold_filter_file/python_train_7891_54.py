s=input()
l=[]
for i in range(0,len(s)-2):
    l.append(abs(int(s[i:i++3])-753))
print(min(l))