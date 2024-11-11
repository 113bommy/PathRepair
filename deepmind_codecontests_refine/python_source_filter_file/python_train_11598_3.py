n=input()
n=n.replace('144', '0') 
n=n.replace('14', '0') 
n=n.replace('1', '0') 
n=set(n)
if(len(n)!=1):
    print("NO")
else:
    for i in n:
        if(i!='0'):
            print("NO")
        else:
            print("YES")