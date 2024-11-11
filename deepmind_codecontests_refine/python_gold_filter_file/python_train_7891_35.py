s=input()

print(min(abs(753-int(s[i:i+3])) for i in range(0,len(s)-2)))