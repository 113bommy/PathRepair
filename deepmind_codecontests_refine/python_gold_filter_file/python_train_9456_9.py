a=input()
op=['+','-']
 
for i in op:
    for j in op:
        for k in op:
            if eval(a[0]+i+a[1]+j+a[2]+k+a[3])==7:
                print(a[0]+i+a[1]+j+a[2]+k+a[3]+"=7")
                exit()