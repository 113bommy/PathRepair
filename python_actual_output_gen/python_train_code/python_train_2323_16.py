n = int(input())
num = input()[-1::-1]
value = int('0b'+num,2)
value += 1
numm = bin(value).split('b')[1]
length = len(numm)
if length!=n:
    numm = '0'*(n-length)  + numm
count = 0
for i in range(n):
    if numm[i]!=num[i]:
        count += 1
print(count)