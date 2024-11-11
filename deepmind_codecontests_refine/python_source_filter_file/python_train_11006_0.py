n = int(input())
c=0
c +=n//100
r=n%100
c +=r//20
r %=20
c +=r//10
r %=10
c +=r//5
r %= 5
print (c)