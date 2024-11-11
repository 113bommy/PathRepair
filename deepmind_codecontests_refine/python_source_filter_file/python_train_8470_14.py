s=input()
if(1000<=int(s)<=9000):
    for i in range(int(s)+1,int(s)+100):
        if(len(set(str(i)))==4):
            print(i)
            break
        