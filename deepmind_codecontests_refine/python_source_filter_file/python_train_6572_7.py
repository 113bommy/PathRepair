n=int(input())
l=[]
for i in range(n):
    s=input()
    l.append(list(s))
count=0
    
for i in range(1,n-1):
    for j in range(1,n-1):
        if(l[i][j]==l[i-1][j-1]==l[i-1][j+1]==l[i+1][j-1]==l[i+1][j+1]=='x'):
            count+=1
            
print(count)