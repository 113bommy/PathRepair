n,k,t=map(int,input().split())
if t>n:
     t=t%n
     t=k-t
if t<k:
     print(t)
elif t<n and t>=k:
     print(k)
