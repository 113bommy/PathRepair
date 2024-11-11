w1,h1,w2,h2=map(int,input().split())	
r=2*(h2+h2+w1)+4	#2*(h2-h1)+w1+w2+w1-w2+2*h1
print(r)