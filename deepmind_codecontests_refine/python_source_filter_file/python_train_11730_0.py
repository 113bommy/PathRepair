tmp = input().split(" ")
n = int(tmp[0])
k = int(tmp[1])
s = list(input())
# flag = 1
# for x in range(26):
#     c = chr(ord('a') + x)
#     tmp = []
#     for i in s:
#         if(i==c and flag):
#             k -= 1
#             if(k==0):flag=0
#         else:
#             tmp.append(i)
#     s = [i for i in tmp]
#     if(not flag):
#         print("".join(s))
#         break

dic = {chr(ord('a')+x):0 for x in range(26)}
for i in s:
    dic[i] += 1
x = -1
sum = 0
while(sum<k):
    x += 1
    sum += dic[chr(ord('a')+x)]
sum -= dic[chr(ord('a')+x)]
print(x)
flag = []
for i in s:
    if(ord(i)-ord('a')==x):
        if(sum<k):
            sum += 1
        else:
            flag.append(i)
    if(ord(i)-ord('a')>x):
        flag.append(i)
print("".join(flag))
