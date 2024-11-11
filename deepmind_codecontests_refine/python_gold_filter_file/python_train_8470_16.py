n=input()
a=set(n)
for i in range(1000,100000):
    k=str(i)
    if(len(set(k))==4):
        if(int(n)>=1000 and int(n)<=9000):
            if(i>int(n)):
                print(i)
                break
        else:
            print("0")
            break