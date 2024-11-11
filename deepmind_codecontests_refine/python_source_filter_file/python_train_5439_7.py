for i in range(int(input())):
    a=int(input())
    b=str(a)
    c=[]
    for j in range(len(b)):
        if b[j]!=0:
            c.append(str(int(b[j])*pow(10,len(b)-1-j)))
            if c[-1]=='0':
                c.remove(c[-1])
print(len(c))
print(" ".join(c))
