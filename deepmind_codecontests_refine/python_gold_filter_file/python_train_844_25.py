n=int(input())
b='abcd'
c=n//4
if c>=1 and n%4!=0:
    c+=1
if c==0:
    print(b[0:n:1])
else:
    b=b*c
    print(b[0:n:1])