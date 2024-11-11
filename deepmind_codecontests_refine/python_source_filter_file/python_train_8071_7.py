s,ans=input(),1
for x in s:
    if '0'<=x<='9': t=ord(x)-48
    if 'A'<=x<='Z': t=ord(x)-55
    if 'a'<=x<='z': t=ord(x)-61
    if x=='-': t=62
    if x=='_': t=63
    
    ans=(ans*(3**(bin(t).count('0')-1)))%1000000007
print(ans)
