n = int(input())
k = list(input())
b = k.count('B')
t = n-b
count = 0
a=[]
if(b%2 != 0 and t%2!=0):
    print(-1)

elif(b==0 or t==0):
    print(0)
    
else:
    c=""
    q = 1
    if(b%(1+1)==0):
        
        while q<n:
            if(k[q] == 'B' and k[q-1]=='B'):
                k[q] = k[q-1] = 'W'
                c+=str(q-1)+" "
                q+=1
                count+=1
            elif(k[q-1] == 'B' and k[q] == "W"):
                k[q-1] = "W"
                k[q] = 'B'
                c+=str(q-1)+" "
                q+=1
                count+=1
            elif(k[q] == 'W' and k[q-1] == "W"):
                q+=1
            else:
                q+=1
    else:
        while q<n:
            if(k[q] == 'W' and k[q-1]=='W'):
                k[q] = k[q-1] = 'B'
                c+=str(q)+" "
                q+=1
                count+=1
            elif(k[q] == 'B' and k[q-1] == "W"):
                k[q] = "W"
                k[q-1] = 'B'
                c+=str(q)+" "
                q+=1
                count+=1
            elif(k[q] == 'B' and k[q-1] == "B"):
                q+=1
            else:
                q+=1
    print(count)
    print(c)