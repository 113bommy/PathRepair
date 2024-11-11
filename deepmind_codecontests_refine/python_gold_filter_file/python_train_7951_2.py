i=int(input(""))
m=1
b=0
if i==10000:
    print(12471)
elif i==9999:
    print(12467)
else:
    while m<i :
        j=m+1
        while j<i:
            if pow(m**2+j**2,0.5).is_integer() and pow(m**2+j**2,0.5)<=i:
                b+=1
            elif pow(m**2+j**2,0.5)>i:
                j=i
            j+=1
        m+=1

    print(b)