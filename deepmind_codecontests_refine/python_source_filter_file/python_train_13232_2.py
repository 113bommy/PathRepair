from sys import stdin,stdout
a,b,c=map(int,stdin.readline().split())
z=list(map(int,stdin.readline().split()));ans=''
f=0;i=0
while i < a:
    if z[i] > c:
        i += 1;f+=1
        while i < a and z[i] > b: i += 1
    else:
        i += 1
for _ in " "*b:
    x=list(map(int,stdin.readline().split()))
    if x[0]==0:ans+=str(f)+' '
    else:
        x[1]-=1
        if z[x[1]]<=c:
            if z[x[1]]+x[2]<=c:z[x[1]]+=x[2]
            else:
                z[x[1]]+=x[2]
                if x[1]==0:
                    if a==1:f=1
                    else:
                        if z[1]<=c:f+=1
                elif x[1]==a-1:
                    if z[x[1]-1]<=c:f+=1
                else:
                    if z[x[1]-1]>c and z[x[1]+1]>c:f-=1
                    elif z[x[1]-1]<=c and z[x[1]+1]<=c:f+=1
stdout.write(ans)