t=int(input())
for i in range(t):
    n=int(input())
    p=input()
    q=input()
    a=[char for char in p]
    b=[char for char in q]
    for i in range(n):
        if a[i]=="0" and b[i]=="1":
            a[i]="2"
            b[i]="0"
    for i in range(n):
        if (i>0 and i<(n-1)):
            if a[i-1]=="1" and b[i]=="1":
                a[i-1]="2"
            elif a[i+1]=="1" and b[i]=="1":
                a[i+1]="2"
        elif i==0:
            if a[i+1]=="1" and b[i]=='1':
                a[i+1]="2"
        else:
            if a[i-1]=="1" and b[i]=="1":
                a[i-1]="2"
    c=0
    for i in range(n):
        if a[i]=="2":
            c+=1
    print(c)