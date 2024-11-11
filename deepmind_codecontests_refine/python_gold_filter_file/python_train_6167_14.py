try:
    for _ in range(int(input())):
        n=int(input())
        x=input()
        a=''
        b=''
        maxi=False
        for i in range(n):
            if x[i]=='0':
                if maxi==False:
                    a+='0'
                    b+='0'
                elif maxi==1 :
                    a+='0'
                    b+='0'
                else:
                    a+='0'
                    b+='0'
            elif x[i]=='1':
                if maxi==False:
                    a+='1'
                    b+='0'
                    maxi=1
                elif maxi==1 :
                    a+='0'
                    b+='1'
                else:
                    a+='1'
                    b+='0'
            else:
                if maxi==False:
                    a+='1'
                    b+='1'
                elif maxi==1 :
                    a+='0'
                    b+='2'
                else:
                    a+='2'
                    b+='0'
        print(int(a))
        print(int(b))
except:
    pass
    
    
        