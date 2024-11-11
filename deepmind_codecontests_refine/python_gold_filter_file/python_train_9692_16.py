
dic1=[]
dic2=[]
n,m=map(int,input().split())
for i in range(n):
    s=input()
    for j in range(m):
        if s[j]=='B':
            dic1.append(i+1)
            dic2.append(j + 1)
r=dic1[len(dic1)//2]
c=dic2[len(dic2)//2]
print(r,c,sep=' ')
