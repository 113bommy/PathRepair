dir=input()
str=input()
str1="qwertyuiopasdfghjkl;zxcvbnm,./"
if dir=='R':
    for i in str:
        a=str1.find(i)
        print(str1[a-1:a],end="")
else:
    for i in str:
        a=str1.find(i)
        print(str1[a+1:a],end="")
    
    
