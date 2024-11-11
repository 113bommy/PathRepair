w1,h1,w2,h2=map(int,input().split())
ans=w1+h1*2+w2+h2*2+4
if w1!=w2:
     ans+=1
print(ans)
          
     
     
