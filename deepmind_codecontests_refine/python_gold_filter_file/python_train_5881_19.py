N = int(input())
str1 = input()
str2 = input()
sum1 = 0
for i in range(N):
    if int(str1[i])>int(str2[i]):
        max, min  = int(str1[i]),int(str2[i])
    else:
        max ,min= int(str2[i]),int(str1[i])
    if max-min>5:
        sum1+=10-(max-min)
    else:
        sum1+=max-min

print(sum1)
