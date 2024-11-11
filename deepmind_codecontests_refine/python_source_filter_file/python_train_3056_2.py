strp = str(input())

arr = strp.split('/')
fl = []
for i in range(len(arr)):
    if arr[i] != '':
        fl.append(arr[i])

str1 = ""

for elem in fl:
    str1 += "/" + elem
if strp == "":
    print("/")
    exit()
print(str1)