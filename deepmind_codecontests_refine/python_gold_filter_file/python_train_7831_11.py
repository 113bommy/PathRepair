def binary_period(string):
    l=len(string)
    if l==2:
        return string
    elif l==1:
        return string
    if ("1" not in string )or ("0" not in string):
        return string
    
    
    
    else:
        string_=string[0]
        for i in range(1,l):
            if string[i-1]!=string[i]:
                string_+=string[i]
            else:
                if string[i]=="0":
                    string_+="1"+string[i]
                elif string[i]=="1":
                    string_+="0"+string[i]
        return string_

t=int(input())
array=[]
for i in range(t):
    array.append(input())
for j in array:
    print(binary_period(j))


        