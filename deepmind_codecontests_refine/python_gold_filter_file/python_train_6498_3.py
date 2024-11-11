a=input()
b=0
for i in range(len(a)):
    c=a.find('bear',i)
    if(c>=0):
        b+=len(a)-c-3
print(b)