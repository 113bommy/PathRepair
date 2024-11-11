x= input()
x=[int(i) for i in x.split(" ")]
n = x[1]
y = input()


while(n!=0):
    i=0
    res=""
    if len (y) == 1:
        res = y
        break
    while(i in range(len(y)-1) and len(y)!=1):
        if y[i] == 'B' and y[i+1] == 'G':
            res= res+y[i+1]+y[i]
            i = i+2
        else:
            res= res + y[i]
            i=i+1
        if i == (len(y)-1):
            res = res + y[i]
            break
            #res = res + y[i]
    n=n-1
    print(n)
    y=res
print(res)
    
