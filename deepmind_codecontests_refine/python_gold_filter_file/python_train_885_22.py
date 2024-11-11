n=eval(input())
a=eval(input())
b=eval(input())
c=eval(input())
x = 0
if ( b - c < a  and n>c):
    x = (n - c)//(b - c)
    n -= x*(b - c)
x += n//a
print(x)
