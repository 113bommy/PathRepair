n = int(input())
lis = list(map(int,input().split()))
li=[]
c=1
for i in range(n):
    if(lis[i]==c):
        li.append(2000+i+1)
        c+=1
if(c==1):
    print('0')
else:    
    print(len(li),*li)        
    