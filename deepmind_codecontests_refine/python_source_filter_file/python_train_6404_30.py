str1 = str(input())
str2 = str(input())
n = len(str1)
list1 = []
for i in range(n-1):
    if str1[i] == str2[i]:
        list1.append('0')
    else:
        list1.append('1')
print(''.join(list1))
