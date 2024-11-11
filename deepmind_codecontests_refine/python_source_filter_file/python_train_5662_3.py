a=input()
b=input()
if a==b:
    print("Yes")
elif len(a)!=len(b):
        print("No")
elif a.count('1')==0 and b.count('1')!=0:
    print("No")
elif b.count('1')==0 and a.count('1')!=0:
    print("No")
else:
    print("Yes")