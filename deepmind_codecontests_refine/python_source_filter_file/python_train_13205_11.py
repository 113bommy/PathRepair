N,A,B = list(map(int,input().split()))
 
v = list(map(int,input().split()))
 
v.sort()
v=v[::-1]
 
a=v[A-1]
is_first = True
end=-1
for i in range(N):
    if v[i]==a:
        if is_first:
            first=i
            is_first=False
    else:
        if not is_first:
            end=i
            break
 
def comb(n,k):
    a = 1
    b = 1
    for i in range(min(n-k,k)):
        a*=n-i
        b*=i+1
    return a//b
#print(comb(3,1))
if end==-1:
    end=N
if first==0:
    print(a)
    print(sum([comb(end,i) for i in range(A,min(end,B+1))]))
else:
    print(sum(v[:A])/A)
    print(comb(end-first,A-first))