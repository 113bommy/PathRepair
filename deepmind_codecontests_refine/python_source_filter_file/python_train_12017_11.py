s = input()

n = len(s)

flag1 = False
flag2 = False
a = 0
b = 0
c = 0
for i in range(n):
    if flag1==False and flag2 == False and s[i]!="+":
        if s[i] == "|":
            a = a+1
    if s[i]=="+":
        flag1=True 
    if flag1==True and flag2 == False and s[i]!="=":
        if s[i] == "|":
            b = b+1
    if s[i]=="=":
        flag2=True 
    if flag1==True and flag2 == True:
        if s[i] == "|":
            c = c+1


if abs(a+b-c) == 2:
    if (a+b>c):
        if (a>b):
            for _ in range(a-1):
                print("|",end = "")
            print("+",end = "")
            for _ in range(b):   
                print("|",end = "")
            print("=",end = "")   
            for _ in range(c+1):
                print("|",end = "")  
        else:
            for _ in range(a):
                print("|",end = "")
            print("+",end = "")
            for _ in range(b-1):   
                 print("|",end = "")
            print("=",end = "")   
            for _ in range(c+1):
                print("|",end = "")  
               
    else: 
        for _ in range(a+1):
            print("|",end = "")
        print("+",end = "")
        for _ in range(b):   
            print("|",end = "")
        print("=",end = "")   
        for _ in range(c-1):
            print("|",end = "")  
    print()                           
elif  (a+b ==c):
    print(s)
else:    
    print("impossible")    




