n=int(input())
s=str(input())
arr=[[0,0,0],[0,0,0],[0,0,0]]
case1=0
for i in range(n):
    if(s[i]=='B'):
        arr[0][i%3]+=1
    elif(s[i]=='R'):
        arr[1][i%3]+=1
    else:
        arr[2][i%3]+=1
ans=0
#print(arr)
arrx=[]
arrx.append(arr[0][0]+arr[1][1]+arr[2][2])
arrx.append(arr[0][0]+arr[1][2]+arr[2][1])
arrx.append(arr[0][1]+arr[1][0]+arr[2][2])
arrx.append(arr[0][1]+arr[1][2]+arr[2][0])
arrx.append(arr[0][2]+arr[1][1]+arr[2][0])
arrx.append(arr[0][2]+arr[1][0]+arr[2][1])
max1=max(arrx)
index1=arrx.index(max1)
#print(n-max1)
s1=''
if(index1==0):
    for i in range(n):
        if(i%3==0):
            s1+='B'
        elif(i%3==1):
            s1+='R'
        else:
            s1+='G'
elif(index1==1):
    for i in range(n):
        if(i%3==0):
            s1+='B'
        elif(i%3==2):
            s1+='R'
        else:
            s1+='G'
elif(index1==2):
    for i in range(n):
        if(i%3==1):
            s1+='B'
        elif(i%3==0):
            s1+='R'
        else:
            s1+='G'
elif(index1==3):
    for i in range(n):
        if(i%3==1):
            s1+='B'
        elif(i%3==2):
            s1+='R'
        else:
            s1+='G'
elif(index1==4):
    for i in range(n):
        if(i%3==2):
            s1+='B'
        elif(i%3==1):
            s1+='R'
        else:
            s1+='G'
elif(index1==5):
    for i in range(n):
        if(i%3==2):
            s1+='B'
        elif(i%3==0):
            s1+='R'
        else:
            s1+='G'
print(s1)


