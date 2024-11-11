t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    flag=0
    a,b="",""
    for i in s:
        if i=="0":
            a+="0"
            b+="0"
        if i=="1":
            if flag==0:
                a+="1"
                b+="0"
                flag=1
            else:
                a+="0"
                b+=i
        else:
            if flag==0:
                a+="1"
                b+="1"
            else:
                a+="0"
                b+=i
    print(a)
    print(b)