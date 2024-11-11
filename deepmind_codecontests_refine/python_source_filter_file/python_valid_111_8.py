t=int(input())
for T in range(t):
    n=int(input())
    
    fin=[]
    #final
    for i in range(n):
        s=""
        cnt=0
        for j in range(i+1):
            s+='('
            cnt+=1;
        j=cnt;
        k=0;
        #print(j)
        while(k<3 and j<3):
            s+=')'
            j+=1;
            s+='('
            k+=1;
        while(k<3):
            s+=')'
            k+=1;
        fin.append(s)
    for i in range(len(fin)):
        print(fin[i])