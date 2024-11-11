c1,c2,c3,c4,c5=list(map(int,input().split()))

total=c1+c2+c3+c4+c5

if total == 0:
    resul=-1
    
elif total%5==0:
    resul=total/5
    #print(resul)
else:
    resul=-1
    
print(resul)