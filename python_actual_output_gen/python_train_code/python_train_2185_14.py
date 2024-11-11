h1,m1,h2,m2,k=map(int,input().split())
s=abs(h2-h1)*60+abs(m2-m1)
n=s-k
print(n)