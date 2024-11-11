n,a,b=map(int,input().split())
c=min(a,b)
z=input().split()
ans,l,r=0,0,n-1
while l<=r:
    #print(l,r,ans)
    if z[l]==z[r]:
        if z[l]=='2':
            if l==r:
                ans+=c
            else:
                ans+=(2*c)
    else:
        if z[l]=='1' and z[r]=='0' or z[l]=='2' and z[r]=='1':
            print(-1)
            exit()
        else:
            if z[l]=='2':
                if z[r]=='0':
                    ans+=a
                else:
                    ans+=b
            else:
                if z[l]=='0':
                    ans+=a
                else:
                    ans+=b
    l+=1
    r-=1
print(ans)
                
                
            
    
