n=input()
a=list(map(int,input().split()))
n=sum(x<0 for x in a)
a=[map(abs,a)]
s=sum(a) if n%2==0 else sum(a)-min(a)*2
print(s)
