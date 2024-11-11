var1 = int(input())
str2 = "Hoshino"
str3 = "Hoshina"


for i in range(0, var1):

    str1 = input()
    if str1.find(str2) >= 0:
        str1 = str1.replace(str2, str3)
        print(str1)


