a=input()
b=input()
v=sorted(a)
v=v[::-1]
x=""
for i in range(len(v)):
    x=x+v[i]
v=x
if(len(a)<len(b)):
    print(v)
else:
    if(b==a):
        print(a)
    else:
        fin=""
        flag=False
        for j in range(len(a)):            
            for k in range(len(a)):
                num=fin+v[k]+''.join(sorted(v[:k:]+v[k+1::]))
                #print(v,num,k)
                if(num<=b):
                    fin+=v[k]
                    #print(fin,v[k],b[k])
                    if(int(v[k])<int(b[k])):
                        flag=True
                        v=v[:k:]+v[k+1::]
                        fin+=v 
                    v=v[:k:]+v[k+1::]
                    break
            if(flag):
                break
        print(fin)