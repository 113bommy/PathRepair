n,a,b=map(int,input().split())
s=input()
c=a+b
A=0
B=0
for i in s:
    if A+B<=c:
        if i=="a":
            A+=1
            print("Yes")
        elif i=="b" and B<b:
            B+=1
            print("Yes")
        else:
            print("No")
    else:
        print("No")