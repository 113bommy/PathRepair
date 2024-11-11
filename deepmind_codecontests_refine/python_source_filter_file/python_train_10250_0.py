str1 = input().split(' ')
str2 = input()
dict1 = {}
for item in str2:
    if dict1.get(item, 0):
        dict1[item] += 1
    else:
        dict1[item] = 1
str3 = sorted(list(dict1.values()), reverse=True)
i = 0
sum = 0
k = int(str1[1])
while 1 :
    a = k - str3[i]
    if a<=0:
        sum += k**2
        break
    else:
        k = k - str3[i]
        sum += str3[i]**2
    ++i;
print(sum)