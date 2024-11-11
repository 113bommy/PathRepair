str = input()
q1=[]
idx=-1
a=[]
count=0
for i in str:
    idx+=1
    if(i =='Q'):
        q1.append(idx)
    if(i == 'A'):
        if(q1 != []):
            a.append(idx)
if(len(q1) <= 1 or len(a) == 0 ):
    print(0)
else:
    for i in range(0,len(q1)-1):
        for j in range(i+1 , len(q1)):
            
            for k in a:
                if(k>q1[j]):
                    break
                elif(k < q1[j] and k>q1[i]):
                    count+=1
print(count)