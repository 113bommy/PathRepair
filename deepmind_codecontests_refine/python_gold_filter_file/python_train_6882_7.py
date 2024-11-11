num = input()
count=0
#for i in num[1:]:
 #   count += int(i)

#print((len(num)-1)*9+int(num[0])+count)
#碰到末尾为9的就会多加一个9

num1 = int(num)-10**(len(num)-1)+1

for i in str(num1):
    count+=int(i)
print((len(num)-1)*9+count)
