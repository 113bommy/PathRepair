
nk=input().split()
n=int(nk[0])
k=int(nk[1])
a_1=[]
b_1=[]
c=0
for n_tr in range (n):
    ab=input().split()
    a=int(ab[0])
    b=int(ab[1])
    a_1.append(min(a,b))
    b_1.append(max(a,b))

if (max(a_1)>k):
    m=max(a_1)-k
    if (m+k<=min(b_1)):
        print(m)

    else:
        print(-1)
    c=c+1

elif (min(b_1)<k):
        m=k-min(b_1)
        if (k-m>=max(b_1)):
            print(m)
        else:
            print(-1)
        c=c+1
if c==0:
    print(0)