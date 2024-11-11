t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    a = []
    blankcount=0

        # continue
    for i in range(n):
        # print(i)
        if s[i]=="?":
            a.append("")
            blankcount+=1
        else:
            a.append(s[i])
    if blankcount==n:
        # print("Here")
        a[0]="B"
        blankcount-=1
    
    while blankcount!=0:
        for i in range(n-1):
            if a[i]=="":
                if a[i+1]=="B":
                    a[i]="R"
                    blankcount-=1
                elif a[i+1]=="R":
                    a[i]="B"
                    blankcount-=1
            if blankcount==0:
                break
        for i in range(1,n):
            if a[i]=="":
                if a[i-1]=="B":
                    a[i]="R"
                    blankcount-=1
                elif a[i-1]=="R":
                    a[i]="B"
                    blankcount-=1
                if blankcount==0:
                    break

    for x in a:
        print(x,end="")
    print()
    