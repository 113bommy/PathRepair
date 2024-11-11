def pr(x):
    print(int(n/x))
    for i in range(int(n/x)):
        print(s[i*x:(i+1)*x])
n,p,q=map(int,input().split())
s=input()
if n%p==0:
    pr(p)
elif n%q==0:
    pr(q)
else:
    for i in range(1,int(n/p)+1):
        if (n-p*i)%q==0:
            print(i+int((n-p*i)/q))
            for j in range(i):
                print(s[j*p:(j+1)*p])
            for j in range(int((n-p*i)/q)):
                print(s[i*p+j*q:i*p+(j+1)*q])
            break
    else:
        print("-1")
        
