n,k,m=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
suma=sum(l)
maximo = 0
for i in range(len(l)):
    t = (suma + min(m-i,k*(n-i)))/(n-i)
    maximo = max(maximo,t)
    suma -= l[i]
print(maximo)