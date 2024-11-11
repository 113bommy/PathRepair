n,k = map(int,input().split())
l = [0]*(n+1)
for i in range(k):
    a,b,c= map(int,input().split())
    if(l[a]==0 and l[b]==0 and l[c]==0):
        l[a]=1
        l[b]=2
        l[c] =3
    else:
        if(l[a]!=0):
            x = l[a]         
            if(x==1):
                l[b]=2
                l[c] =3
            elif(x==2):
                l[b] = 1
                l[c] =3
            elif(x==3):
                l[b] = 2
                l[c] =1
        elif(l[b]!=0):
            x = l[b]         
            if(x==1):
                l[a]=2
                l[c] =3
            elif(x==2):
                l[a] = 1
                l[c] =3
            elif(x==3):
                l[a] = 2
                l[c] =1
        elif(l[c]!=0):
            x = l[c]         
            if(x==1):
                l[b]=2
                l[a] =3
            elif(x==2):
                l[b] = 1
                l[a] =3
            elif(x==3):
                l[b] = 2
                l[a] =1
    
    
for i in l[1:]:
    print(i,end=" ")