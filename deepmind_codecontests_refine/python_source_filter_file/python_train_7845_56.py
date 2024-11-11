n=int(input())
ar=[]
w=60
i=1
r=3
while w<179:
    i+=1
    r+=1
    ar.append(w)
    w=180*i/r
for i in range (n):
    m=int(input())
    if m in ar:
        print ('YES')
    else:
        print ('NO')