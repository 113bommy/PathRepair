s=input()
n=len(s)-1
prev=0
ans=0
for i in range(n-3):
    if(s[i:i+4]=="bear"):
        bwc=i+1-prev
        prev=i+1
   #     print(n)
        endchar=n-i-3
     #   print(bwc,endchar)
        ans+=bwc*endchar
        i+=3
print(ans)        
    
