def magic(n,d,l):
    #sum arr[0::2]-arr[1::2]==d
    arr=[1]*(n)
    ans=[None]*n
    odd=arr[0::2]
    even=arr[1::2]
    if d>0:
        val=d-(sum(odd)-sum(even))
        while val:
            for i in range(len(odd)):
                if val:
                    odd[i]+=1
                    val-=1
                else:
                    break
    if d<0:
        val=abs(d)-(sum(even)-sum(odd))
        while val:
            for i in range(len(even)):
                if val:
                    even[i]+=1
                    val-=1
                else:
                    break
    if max(odd)>l or max(even)>l:
        return -1
    ans[0::2]=odd
    ans[1::2]=even
    print(*ans)
    return ""
a,b,c=map(int,input().strip().split())
print(magic(a,b,c))