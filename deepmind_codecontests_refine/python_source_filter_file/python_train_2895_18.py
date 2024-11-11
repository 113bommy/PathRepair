*s,=map(int,input())
n=len(s)
a=sum(s)+n//2-sum(s[::2])*2
print(min(a,n-a))