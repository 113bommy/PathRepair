k=input()
a=''
k=k.lower()
b=['a','e','i','o','u']
for i in range(0,len(k)):
        if(k[i] not in b):
            a=='.'
            a+=k[i]
print(a)