


n,k= map(int,input().split())




t=[]
p=0
h=0
for j in range(1,int(n**(0.5))+1):

    if n%j==0:
        if j!=n//j:
            t.append(n//j)
            p+=1
        if p==k:
            print(j)
            h+=1
            break




if h==0:
    p-=k

    if abs(p)>len(t):
        print(-1)
    else:
        print(t[p])
