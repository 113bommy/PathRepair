n,z=map(int,input().split())
li=sorted(list(map(int,input().split())))
#print(li)
i,j=0,n//2
count=0
n=len(li)

#print(li[i],li[j])
#print(li[k],j)
while i<=n//2 and j<n:
    if li[j]-li[i]>=z:
        #print(li[j],li[i])
        count+=1
        i+=1
        j+=1
    else:
        j+=1
print(count)
"""

    #    f=1
    #    count+=1
if f==0:
    print('0')
else:
    print(count)
print(count)
"""