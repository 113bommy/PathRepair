s=input()
xlist=[abs(int(s[i:i+2])-753) for i in range(0,len(s)-3)]
print(min(xlist))