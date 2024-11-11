n, m = map(int, input().split(':'))
n1, m1 = map(int, input().split(':'))
a = n*60 + m
b = n1*60 + m
c = (a+b)//2
n2 = str(c//60)
m2 = str(c%60)
if len(n2)==1: n2 = '0'+n2
if len(m2)==1: m2 = '0'+m2
print(n2+':'+m2)
