str1 = input()
str2 = input()
output = -1

if len(str1) > len(str2):
    output = len(str1)
elif len(str2) > len(str1):
    output = len(str2)
elif str1 != str2:
    output = len(str1)
else:
    output = 0

print(output)
