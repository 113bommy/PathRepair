w1,h1,w2,h2=map(int,input().split())
ans=(h1+h2+2)*2 
ans+=(max(w1,w2)*2)
print(ans)