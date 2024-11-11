n= int(input())
for i in range(1,3501):
    for j in range(1,3500):
        if (4*i*j-n*i-n*j)!=0:
         w= (n*i*j)/(4*i*j-n*i-n*j)
         if w.is_integer():
            print(str(i)+" "+str(j)+" "+str(int(w)))
            exit()
