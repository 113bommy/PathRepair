t = int(input())
def results(n,x):
    a=[]
    b = []
    c = 0
    for i in x:
        if i==0:
            if c == 0:
                a.append(0)
                b.append(0)
            elif c >= 1:
                a.append(0)
                b.append(i)
        elif i==2:
            if c==0:
                a.append(1)
                b.append(1)
            elif c>=1 :
                a.append(0)
                b.append(i)
        elif i == 1:
            if c == 0:
                a.append(1)
                b.append(0)
            elif c >= 1:
                a.append(0)
                b.append(i)
            c+=1
    for i in a:
        print(i,end="")
    print('')
    for i in b:
        print(i,end="")
    print("")





for _ in range(t):
     n = int(input())
     str = input()
     x = []
     for i in str:
         x.append(int(i))
     results(n,x)
