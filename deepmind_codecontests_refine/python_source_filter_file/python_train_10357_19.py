a = ["","one","two","three","four","five","six","seven","eight","nine"]
b = ["","","twen","thir","for","fif"]
c = ["","-one","-two","-three","-four","-five","-six","-seven","-eight","-nine"]
n = int(input())

if n<10:
    print (a[n])
elif n == 11:
    print ("eleven")
elif n == 12:
    print ("twelve")
elif n == 10:
    print ("ten")
elif n == 14:
    print ("fourteen")
elif n == 18:
    print ("eighteen")

elif n//10 == 1:
    if n<16:
        print (str(b[n-10])+"teen")
    else:
        print (str(a[n-10])+"teen")
elif n//10<6:
    print (str(b[n//10]+"ty"+str(c[n%10])))
else:
    if n//10 !=  8:
        print (str(a[n//10]+"ty"+str(c[n%10])))
    else:
        print ("eight"+str(c[n%10]))
if n == 0:
    print ("zero")
