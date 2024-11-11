string=input()
count=0
if(len(string)<7):
    count+=1
    print("NO")
else:
    for i in range((len(string)-7)+1):
        if(string[i]=="0" and ("1" not in string[i:i+7])):
            #print(i,end="\n")
            print("YES")
            count+=1
            break
        if(string[i]=="1" and ("0" not in string[i:i+7])):
            print("YES")
            #print(i,end="\n")
            count+=1
            break
if(count==0):
    print("NO")
