n=int(input())
b=[]
for i in range(n):
    a= list(map(int, input().split()))
    a.append(i+1)
    b.append(a)
def fn(a):
    return a[3]
b.sort(key=fn)
def fn1(b,n):
    for i in range(n):
        for j in range(n):
            c=0
            for k in range(3):
                if b[i][k]<b[j][k]:c+=1
            if c==3:break
            if j==n-1:return b[i][4]
print(fn1(b,n))

