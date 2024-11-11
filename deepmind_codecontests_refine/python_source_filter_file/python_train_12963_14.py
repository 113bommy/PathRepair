l=[[0,0] for i in range(366)]
n=int(input())
for u in range(n):
    x=input().split()
    if(x[0]=='M'):
        for i in range(int(x[1])-1,int(x[2])):
            l[i][0]+=1
    else:
        for i in range(int(x[1])-1,int(x[2])):
            l[i][1]+=1
s=0
for i in l:
    s=max(s,max(i)*2)
print(s)
