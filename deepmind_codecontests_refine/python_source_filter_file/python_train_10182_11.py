n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ea=[]
eb=[]
for i in range(3):
    if(a[i]<b[i]):
        ea.append((a[i],b[i]))
    elif(a[i]>b[i]):
        eb.append((b[i],a[i]))
ea.sort(reverse=True)
eb.sort(reverse=True)
def main(ea,n):
    if(len(ea)==1):
        fa=n%ea[0][0]+n//ea[0][0]*ea[0][1]
    elif(len(ea)==2):
        ga,gb=ea[0]
        ba,bb=ea[1]
        fa=n
        for i in range(n+1):
            if(ga*i>n):
                break
            k=n-ga*i
            tmp=i*gb+k%ba+(k//ba)*bb
            fa=max(tmp,fa)
    elif(len(ea)==3):
        ga,gb=ea[0]
        sa,sb=ea[1]
        ba,bb=ea[2]
        fa=n
        if(ga==sa):
            return main([ea[0],ea[2]],n)
        if(sa==ba):
            return main([ea[0],ea[1]],n)
        for i in range(n+1):
            if(ga*i>n):
                break
            for j in range(n+1):
                if(ga*i+sa*i>n):
                    break
                k=n-ga*i-sa*j
                tmp=i*gb+j*sb+k%ba+k//ba*bb
                fa=max(tmp,fa)
    else:
        fa=n
    return fa
n=main(ea,n)
n=main(eb,n)
print(n)