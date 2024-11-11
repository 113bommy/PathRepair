




if __name__=='__main__':
    n=int(input())
    s=input()
    i=0
    ans=0
    while(i<n):
        r,l,u,d=0,0,0,0
        g=i
        while(g<n):
            if(s[g]=='R'):
                r+=1
            elif(s[g]=='L'):
                l+=1
            elif(s[g]=='U'):
                u+=1      
            elif(s[g]=='D'):
                d+=1
      
            if(d==u and l ==r):
                print("i-> ",i," g-> ",g)
                ans+=1
            g+=1  
        i+=1
    print(ans) 
