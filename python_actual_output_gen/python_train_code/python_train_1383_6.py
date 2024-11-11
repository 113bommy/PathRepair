i = int(input(""))
s = input()
count = 0
result = ""
a = 0
for k in range(i):
    if(s[0] == "b"):
        count+=1
        s = s[1:]
    elif (s[0] == "w"):
        if (count !=0):
            result = result+str(count)+" "
            a+=1    
        s = s[1:]
        count = 0

if count != 0:
    print(a+1)
    print(result + str(count))
else:
    print(a)
    if (result != ""):
        print(result) 