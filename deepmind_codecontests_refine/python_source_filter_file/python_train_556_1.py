l=[]
l=[list(map(int,input().split())) for i in range(3)]
print(l)
sum1=sum( sum(x) if isinstance(x, list) else x for x in l ) 
sum_final=sum1//2

print(sum_final)
l[0][0]=(sum_final - (l[0][1]+l[0][2]))
l[1][1]=(sum_final - (l[1][0]+l[1][2]))
l[2][2]=(sum_final - (l[2][0]+l[2][1]))
#print(l[0][1],l[0][2])
#print(l1)

for i in range(3):
    print(l[i][0],l[i][1],l[i][2])


#sum1=int(sum(list(a[]))/2)


