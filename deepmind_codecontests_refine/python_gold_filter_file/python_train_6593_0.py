n=int(input())
a=input()
b=input()
l,r=0,0
nike=0
poly=0
if len(a)*len(b)>n:
    for i in range(n):
        x=a[l%(len(a))]
        y=b[r%(len(b))]
        if x==y:
            l+=1
            r+=1
            continue
        else:
            #print(0)
            if x=="R":
                if y=="P":
                    nike+=1
                else:
                    poly+=1
            elif x=="P":
                if y=="S":
                    nike+=1
                else:
                    poly+=1
            else:
                if y=="R":
                    nike+=1
                else:
                    poly+=1
        l+=1
        r+=1
else:
    for i in range(len(a)*len(b)):
        x=a[l%(len(a))]
        y=b[r%(len(b))]
        if x==y:
            l+=1
            r+=1
            continue
        else:
            if x=="R":
                if y=="P":
                    nike+=1
                else:
                    poly+=1
            elif x=="P":
                if y=="S":
                    nike+=1
                else:
                    poly+=1
            else:
                if y=="R":
                    nike+=1
                else:
                    poly+=1
        l+=1
        r+=1
    #print(nike,poly)
    nike=nike*(n//(len(a)*len(b)))
    poly=poly*(n//(len(a)*len(b)))
    rem=n%(len(a)*len(b))
    l,r=0,0
    for i in range(rem):
        x=a[l%(len(a))]
        y=b[r%(len(b))]
        if x==y:
            l+=1
            r+=1
            continue
        else:
            if x=="R":
                if y=="P":
                    nike+=1
                else:
                    poly+=1
            elif x=="P":
                if y=="S":
                    nike+=1
                else:
                    poly+=1
            else:
                if y=="R":
                    nike+=1
                else:
                    poly+=1
        l+=1
        r+=1
print(nike,poly)