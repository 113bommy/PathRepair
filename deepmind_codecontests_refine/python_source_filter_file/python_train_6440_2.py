n,a,b=map(int,input().split())
s=input()
for i in s:
    if a+b>0:
        if i=="a":
            a-=1
            print("Yes")
            continue
       elif i=="b" and b>0:
            b-=1
            print("Yes")
            continue
    print("No")
