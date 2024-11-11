
x=str( input())
count=0
counted=0
for i in x:
    if i.isdigit():
        counted=counted+ int(i)
        count+=1

finalcount=0
# if num contained less than 2 digit 
if (len(x)<2):
    print("0")
elif(int(x)==10 or counted<10):
    print("1")
else:
    # if the sum was more  than 1 digit 
    if( counted >10):
        while len(str(counted)) >1:
            temp =0
            counted=str(counted)
            for i in counted:
                temp+=int (i)
            finalcount+=1
            counted=temp
        print(finalcount+1)


