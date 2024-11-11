def fact(  b):
    if(b == 0):
        return 1;
    if( b == 1):
        return 1;
    return b*fact(b - 1);
n = int(input())
p = fact(n);
t = p/(fact(n - 5)*fact(5)) + p/(fact(n - 6)*fact(6)) +  p/(fact(n - 7)*fact(7))
t = int(t)
print(t);
