s = input()
a = ord(s[0]) - ord('a') + 1
b = int(s[1])
if (a == 1 and b == 1) or (a == 1 or b == 8) or (a == 8 and b == 1) or (a == 8 and b == 8):
    print(3)
elif (a == 1 or b == 1 or a == 8 or b == 8):
    print(5)
else:
    print(8)
    

