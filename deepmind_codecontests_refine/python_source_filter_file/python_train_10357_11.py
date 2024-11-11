a=int(input())






t=['zero','one','two','three','four','five','six','seven','eight','nine']

y=['ten','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']

g=['eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen',
   'eighteen',
   'ninteen']





if a<10:
    print(t[a])
elif a==10:
    print(y[0])
elif 10<a<20:
    print(g[a-11])
else:
    x=''
    
    x+=y[int(str(a)[0])-1]
    if str(a)[-1]=='0':
        print(x)
    else:
        x+='-'
        x+=t[int(str(a)[-1])]
        print(x)
    
    
