w1,h1,w2,h2=map(int,input().split())
if(w1>w2):
    ans=h1+h2+2+w2+1+h2+h1+2+w1
if(w2>w1):
    ans=h1+h2+2+w2+1+h2+1+w2-w1+h1+w1
if(w1==w2):
    ans=h1+h2+w2+1+h1+h2+1+w1+2
print(ans)
    