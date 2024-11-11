n=int(input())
a= list(map(int, input().split()))
a.sort()
def list_to_str(a):
    y=''
    for i in range(len(a)):y=y+str(a[i])
    return y
def fn(n,a):
    for i in range(n-1):
        for j in range(i+1,n):
            t1=(a[i]+a[j])
            if t1 in a:
                l=[str(a.index(t1)+1),' '+str(j+1),' '+str(i+1)]
                return list_to_str(l)
    return -1
print(fn(n,a))
