s=str(input())
t=str(input())
if s[0]==t[0]:
    print(abs(int(s[1])-int(t[1])))
    for i in range(abs(int(s[1])-int(t[1]))):
        if int(s[1])-int(t[1])>0:
            print("D")
        else:
            print("U")
elif s[1]==t[1]:
    print(abs(ord(s[0])-ord(t[0])))
    for i in range(abs(ord(s[0])-ord(t[0]))):
        if ord(s[0])-ord(t[0]):
            print("R")
        else:
            print("L")
else:
    print(max(abs((int(s[1])-int(t[1]))),abs(ord(s[0])-ord(t[0]))))
    for i in range(min(abs(ord(s[0])-ord(t[0])),abs(int(s[1])-int(t[1])))):
        if int(s[1])-int(t[1])>0 and ord(s[0])-ord(t[0])<0:
            print("RD")
        elif int(s[1])-int(t[1])<0 and ord(s[0])-ord(t[0])>0:
            print("LU")
        elif int(s[1])-int(t[1])>0 and ord(s[0])-ord(t[0])>0:
            print("LD")
        else:
            print("RU")
    for i in range(max(abs((int(s[1])-int(t[1]))),abs(ord(s[0])-ord(t[0])))-min(abs(ord(s[0])-ord(t[0])),abs(int(s[1])-int(t[1])))):
        if abs(int(s[1])-int(t[1]))>=abs(ord(s[0])-ord(t[0])):
            if int(s[1])>int(t[1]):
                print("D")
            else:
                print("U")
        else:
            if s[0]>t[0]:
                print("L")
            else:
                print("R")
            
            
    