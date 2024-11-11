a=int(input())
b=int(input())
c=int(input())
d=int(input())
A=a^b;B=c|d;C=b&c;D=a^d
print(((A&B)^(C|D)))