from bisect import bisect_left,bisect_right
a,b,q=map(int,input().split())
s=[-(10**21)]+[int(input())for _ in range(a)]+[10**21]
t=[-(10**21)]+[int(input())for _ in range(b)]+[10**21]
for _ in range(q):
  x=int(input())
  s1,s2=s[bisect_right(s,x)-1],s[bisect_right(s,x)]
  t1,t2=t[bisect_right(t,x)-1],t[bisect_right(t,x)]
  ans=10**11
  for i in [s1,s2]:
    for j in [t1,t2]:
      ans=min(ans,abs(i-j)+min(abs(x-i),abs(x-j)))
print(ans)