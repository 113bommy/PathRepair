N=int(input())
s=list(map(int,input().split()))
n=max(s)
s.remove(n)
q=n
for i in s:
    t=abs(n//2-i)
    if q>=t:
        q=t
        w=str(n)+" "+str(i)
print(w)        
    