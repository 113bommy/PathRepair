import re
k = int(input())
num1 = '1' + input() + '1'

str1='[1]{'+str(k+2)+',}'
str2='1' * (k+1)
num = re.sub(str1,str2, num1)
print(num)
sum_num = 0
#st = '1' * (k + 1)
if k != 0 :
 #   num = re.sub(r'[1]{10,}', st, num1)
    sum_num = len(num1) - len(num)
#else:
    #num = num1
num_one = [i for i,v in enumerate(num) if v == '1']
for i in range(1,len(num_one) - k) :
    if k == 0:
        temp = num_one[i] - num_one[i-1] - 1
        sum_num += temp * (temp + 1) // 2
    else :
        temp = (num_one[i] - num_one[i-1]) * (num_one[i + k] - num_one[i + k - 1])
        sum_num += temp
print(sum_num)