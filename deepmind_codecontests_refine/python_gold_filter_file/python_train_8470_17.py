a=input()
if(1000<=int(a)<=9000):
    for i in range(int(a)+1,int(a)+200):
        if(len(set(str(i)))==4):
            print(i)
            break
            