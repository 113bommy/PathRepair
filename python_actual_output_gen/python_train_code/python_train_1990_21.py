def nearest(n):
    i,z=n,True
    while i<n+4 and z:
        j=i
        s=[]
        while j>0:
            s.append(j%10)
            j=j//10
        if sum(s)%4==0:
            return i
        else:
            i+=1
n=int(input())
print(nearest(n))
