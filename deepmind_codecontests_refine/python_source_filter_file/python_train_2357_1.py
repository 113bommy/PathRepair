n=int(input())
a=int(input())
b=int(input())
if a>=b:
    l=a
    s=b
    if n-a>=3*l+2*b:
        print(1)
    if n-a<3*l+2*b and n-a>a+b:
        print(2)
    if n-a<a+b and n-a>=a:
        print(3)
    if n-a<a and n-a>=b:
        print(4)
    if n-a<b and n-b>=b:
        print(5)
    if n-a<b and n-b<b:
        print(6)
else:
    l=b
    s=a
    if n-l>=1*l+4*s:
        print(1)
    if n-l<l+4*s and n-l>=2*s:
        print(2)
    if n-l<2*s and n-l>=s:
        print(3)
    if n-l<s and n>=4*s:
        print(4)
    if n-l<s and n>=2*s and n<4*s:
        print(4)
    if n-l<s and n-s<s:
        print(6)
