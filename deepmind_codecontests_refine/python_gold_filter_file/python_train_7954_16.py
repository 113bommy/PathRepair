a = input()
#a=list(a)

ant,pos =0,0

h=[]

j =-1
used_ant =0
used_post =1
ti=0
while a[ti]!="^":
    ti+=1

    

for x in range(0,len(a)):
    
    if j == -1 and a[x]!="^":
        if a[x]!="=":
            ant+= int(a[x])*(ti-used_ant)
            used_ant+=1
        else:
            used_ant+=1
        
    
    elif (j==1) and (a[x]!="^"):
        if a[x]!="=":
            pos += int(a[x])*used_post
            used_post+=1
        else:
            used_post+=1
        
    elif(a[x]=="^"):
        j=1

if (ant == pos):
    print("balance")
elif (ant<pos):
    print("right")
else:
    print("left")