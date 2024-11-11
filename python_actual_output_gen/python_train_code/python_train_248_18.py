n = int(input())
s=['o']*n
a=1
b=1

s[a-1]='O'
s[b-1]='O'
while(a+b<n):
    c=a+b
    a=b
    b=c

    s[b-1]='O'
print("".join(s))
