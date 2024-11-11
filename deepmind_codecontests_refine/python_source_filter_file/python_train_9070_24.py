w1,h1,w2,h2=list(map(int,input().split()))
c=(max(w1,w2)+2)*(h1+h2+2) - abs(w1*h1-w2*h2)-(w1*h1+w2*h2)
print(c)