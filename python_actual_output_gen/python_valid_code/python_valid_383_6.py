n,a,b=map(int,input().split())
v=[int(i) for i in input().split()]
v.sort(reverse=True)
m=v[a-1]
mm=v.count(m)
cnt=0
for i in range(n):
    if v[i]>m:
        cnt+=1
    else:
        break

def fact(n):
    if n==0 or n==-1:
        return 1
    return fact(n-1)*n
def comb(n,k):
    return fact(n)//fact(n-k)//fact(k)

    
ans=0
#print('mm,cnt',mm,cnt)
for i in range(min(mm+cnt-a,b-cnt)+1):
    ans+=comb(mm,a-cnt+i)
    #print(i,ans)
if m!=v[0]:
    ans=comb(mm,a-cnt)
print(sum(v[0:a])/a)
print(ans)
