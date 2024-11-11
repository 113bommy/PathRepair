n=int(input())
m=input()
cnt=(n-11)//2
cntt=cnt
res=''
for i in m:
    if i=='8':
        if cnt>0:
            cnt-=1
        else:
            res=res+i    
        
    else:
        if cntt>0:
            cntt-=1
        else:
            res=res+i
if res[0]=='8':
    print("YES")            
else:
    print("NO")        