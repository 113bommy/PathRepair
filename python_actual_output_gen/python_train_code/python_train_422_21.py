x=input()
key="qwertyuiopasdfghjkl;zxcvbnm,./"
arr=input()
if(x=="R"):
    for i in arr:
        print(key[key.index(i)-1],end='')
else:
    for i in arr:
        print(key[key.index(i)-1],end='')