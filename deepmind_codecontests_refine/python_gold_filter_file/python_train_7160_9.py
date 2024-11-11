s = input()
a = s[:(len(s)-1)//2:]
b = s[(len(s)+1)//2:]
if a == b and a == a[::-1]:
     print("Yes")
else:
     print("No")