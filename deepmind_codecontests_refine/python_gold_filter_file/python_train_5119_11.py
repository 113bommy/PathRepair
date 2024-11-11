def fail_student(n,m,l):
    d=[]
    for i in range(n):
        k=sorted(l[:i])
        s=sum(k)
        j=0
        while s+l[i]>m:
            s-=k.pop()
            j+=1
        d.append(j)
    return d

n,m=map(int,input().split())
l=list(map(int,input().split()))
print(*fail_student(n,m,l))