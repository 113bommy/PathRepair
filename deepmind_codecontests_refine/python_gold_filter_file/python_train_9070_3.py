w1,h1,w2,h2=map(int,input().split())
k=0
k=k+w1+2
k=k+h1*2
k=k+(w1-w2)
k=k+h2*2
k+=w2+2
print(k)
