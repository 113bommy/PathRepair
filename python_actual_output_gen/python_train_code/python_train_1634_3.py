a = input()
count=0
i=1
while i in range(1,len(a)) and count<1:
    if not 'A'<=a[i]<='Z':
        count+=1
    i+=1
if count>=1:
    print(a)
else:       
    a=a.capitalize()
    print(a)
