a=input()
a=int(a)
b=input()
c=0
for i in range (a):
    try:
        if(b[i+1]<b[i]):
            for j in range(i+1,a):
                print(b[j])
            break
            
        else:
            print(b[i],end="")
    except:
        pass

    
