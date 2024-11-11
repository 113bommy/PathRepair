st=input()
st1=""
vo=['a','e','i','o','u','A','E','I','O','U']
for i in st:
    if(i in vo):
        continue
    else:
        st1=st1+'.'+i.lower()
        
print(st1)
        