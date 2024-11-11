n=input()
a=list(map(int,input().split()))
n=sum(x<0 for x in a)
a=list(map(lambda x: abs(x),a))
m=min(a)
s=sum(a) if n%2==0 else sum(a)-m 
print(s)
