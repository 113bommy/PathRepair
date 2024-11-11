t=int(input())
def change(s,n):
    d=[]
    for i in range(n-1,-1,-1):
        if s[i]=='1':
            d.append('0')
        else:
            d.append('1')
    s=''.join(map(str,d))+s[n:]
    return(s)
while t>0:
    n=int(input())
    a=input()
    b=input()
    i=0
    d=[]
    while(i<n):
        if a[n-i-1]==b[n-i-1]:
            i+=1
            continue
        if a[i]==b[n-i-1]:
            a=change(a,1)
            a=change(a,n-i)
            d.append(1)
            d.append(n-i)
            i+=1
        else:
            a=change(a,n-i)
            d.append(n-i)
            i+=1
    print(len(d),*d)
    
    t-=1
