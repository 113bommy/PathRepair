a= int (input())
for i in range(a):
    s=input()
    w=0
    b=sorted(s)
    for j in range(len(s)-1):
        if b[j]==b[j+1]:
            w+=1
    else:
        c=ord(b[0])
        d=ord(b[-1])
        e=d-c
        f=len(s)-1
        if(f==e) and w>=0:
            print("Yes")
        else:
            print("No")

   