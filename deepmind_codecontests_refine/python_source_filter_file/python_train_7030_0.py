st = input()
string = list(st)
print(string)
s=str()
n = int(len(string))
string.append(4)
print(string)
for i in range(n):
    #print(string[i]," ",string[i-1]," ")
    if(string[i]==string[i-1]):
        for j in range(ord('a'),ord('z')+1):
           # print(string[i],chr(j))
            if(string[i]!=chr(j)):
                #print("banna")
                if(chr(j)!=string[i+1]):
                    s+=chr(j)
                    string[i]=chr(j)
                        #print("banna")
                    break;
    else:
        #print("ki")
        s+=string[i]

    
print(s)
