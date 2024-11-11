l1 = input()
l2 = input()
str = ""
for i in range(len(l1)):
    if l1[i] == l2[i]:
        str+="0"
    else:
        str+="1"
print(str)
