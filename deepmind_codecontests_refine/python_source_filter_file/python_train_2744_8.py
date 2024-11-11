n=int(input())
z=[]
ct=0
b=[]
for i in range(n):
    z+=[list(map(int,input().split()))]
for i in range(n-1):
    if(z[i][0]==z[i+1][0]) and (z[i][1]==z[i+1][1]):
        ct=ct+1
    else:
        if(ct!=0):
            b+=[ct]
        ct=0
if(b==[]):
    print('1')
else:
    print(max(b)+1)
        
