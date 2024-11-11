n,a,list1= int(input()),input(),[]
import math
for i in range(0,n):
    if int(a[i]) != 9 and int(a[i]) != 6 and int(a[i]) != 4  and int(a[i]) != 8 and int(a[i]) != 1 and int(a[i]) != 0:
        list1 = list1 + [int(a[i])]
    elif int(a[i]) == 2:
        list1 = list1 + [2]
    elif int(a[i]) == 6:
        list1 = list1 + [int(a[i])-1]+ [3]
    elif int(a[i]) == 9:
        list1 = list1 + [7] + [2] + 2*[3]
    elif int(a[i]) != 1 and int(a[i]) != 0:
        list1 = list1 + [int(a[i])-1]+ int(math.log2(int(a[i])))*[2]
        

i = [str(integer) for integer in sorted(list1, reverse=True)]
shazly = "".join(i)
print(int(shazly))