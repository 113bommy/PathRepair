w=input().split(" ")
n=int(w[0])
m=int(w[1])
formax=n-m
maxx=int((formax)*(formax+1)/2)
a=n//m
b=n%m
minn=int((b*(a*(a+1)/2))+((m-b)*(a*(a-1)/2)))
print(str(minn)+" "+str(maxx))
