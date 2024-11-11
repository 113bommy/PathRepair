n,m=input().split()
n,m=int(n),int(m)
#print(n)
#print(m)
c=input().split()
#print(c)
c=[int(j) for j in c]
a=input().split()
#print(a)
a=[int(i) for i in a]
i,j=0,0
c1=0
#print(c)
#print(a)
while(j<m and i<n):
    if a[j]>=c[i]:
        #print(str(a[j])+" "+str(c[i]))
        c1+=1
        i+=1
        j+=1
    #elif a[j]==c[i]:
        #j+=1
    else:
        i+=1
#print(str(j)+" "+str(i))
print(c1)