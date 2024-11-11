def team(l,r,a):
    total=0
    if(l==0 and r==0):   #case where left hand and right hand players didnt exist
        if(a%2==0):
            return a
        else:
            return a-1
        
    if(l==0):          #cases where left hand players didnt exist
        if(a==0):
            return 0
        if(a!=0 and a>r):
            total=2*r
            a=a-r
            if(a%2==0):
                return total+a
            else:
                return total+a-1
        
        if(a!=0 and a<=r):
            return 2*a
  
        
    if(r==0):          #cases where right hand players didnt exist
        if(a==0):
            return 0
        if(a!=0 and a>l):
            total=2*l
            a=a-l
            if(a%2==0):
                return total+a
            else:
                return total+a-1
        
        if(a!=0 and a<=l):
            return 2*a 
        
    if(a==0):
        if(r>=l):
            return 2*l
        else:
            return 2*r
        
    if(l==r):
            if(a%2==0):
                return 2*r+a
            else:
                return 2*r+a-1 
            
    if(l>r):
        temp=l-r
        total=2*r
        if(a<=temp):
            return total+2*a
        else:
            total=total+2*temp
            a=a-temp
            if(a%2==0):
                return total+a
            else:
                return total+a-1 
         
    if(r>l):
        temp=r-l
        total=2*l
        if(a<=temp):
            return total+2*a
        else:
            total=total+2*temp
            a=a-temp
            if(a%2==0):
                return total+a
            else:
                return total+a-1 


lst=input().split()

l=int(lst[0])
r=int(lst[0])
a=int(lst[0])
rval=team(l,r,a)
print(rval)
#print("We can construct team with {} members ".format(valueReturned))

