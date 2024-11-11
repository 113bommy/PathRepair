while int(input()):
 s=list(map(int,input().split()))
 n=len(s)
 a=sum(s)/n
 print((sum(x*x for x in s)/n-a*a)**.5)
