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
        while(k<n and j<n):
            s+=')'
            j+=1;
            s+='('
            k+=1;
        while(k<n):
            s+=')'
            k+=1;
        fin.append(s)
    for i in range(len(fin)):
        print(fin[i])