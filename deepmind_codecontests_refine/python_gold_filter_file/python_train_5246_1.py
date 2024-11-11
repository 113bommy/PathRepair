n=int(input())
a=list(input())
b = a[::-1]
if a.count("R")==0:
    s=0
    t=0
    for i in range(0,len(b)):
        if b[i]=="L":
            s=n-(i)
            break
    for i in range(0,len(a)):
        if a[i]=="L":
            t=i
            break
    print(s,t)
elif a.count("L")==0:
    s=0
    t=0
    for i in range(0,len(a)):
        if a[i]=="R":
            s=i+1
            break
    for i in range(0,len(b)):
        if b[i]=="R":
            t=n-i+1
            break
    print(s,t)
else:
    s=0
    t=0
    for i in range(0,len(a)):
        if a[i]=="L":
            t=i+1
            break
    for i in range(t-1,len(a)):
        if a[i]!="L":
            s=i
            break
    print(s,t)
