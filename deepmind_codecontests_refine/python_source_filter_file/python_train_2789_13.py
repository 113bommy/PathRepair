a=int(input())
b=list(map(int,input().split()))
c=sum(b)
d=[(c-x)*x for x in b]
e=sum(d)
 print(e/2)