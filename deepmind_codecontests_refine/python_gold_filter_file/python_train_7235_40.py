n=int(input())
mas=[]
if n>1:
    mas=input().split(" ")
    for i in range(len(mas)):
        mas[i]=int(mas[i])
    ish=[]
    for i in range(len(mas)):
        ish.append(0)
    s=0
    r=0
    for i in range(len(ish)):
        if i>0:
          s+=abs(mas[i]-mas[i-1])
        else:
            s+=abs(mas[i])
    print(s)
else:
    print(0)
    
