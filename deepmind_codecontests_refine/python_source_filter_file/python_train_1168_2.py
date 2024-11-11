import sys
input=sys.stdin.readline #FOR READING STRING/TEXT INPUTS. note that this will also append '\n' to the back of the input.


t=int(input()[:-1])
for _ in range(t):
    a,b,p=[int(x) for x in input().split()]
    s=input()[:-1]
    s=s[:-1]+'Z' #so the last value is counted when the loop terminates
    
    c=''
    total=0
    for x in s:
        if c!='' and x!=c:
            if c=='A':
                total+=a
            elif c=='B':
                total+=b
        c=x
    
    c=''
    total2=0
    i=0
    print(s)
    for x in s:
        i+=1
        if c!='' and x!=c:
            if c=='A':
                total2+=a
            elif c=='B':
                total2+=b
        if total-total2<=p:
            break
        c=x
    print(i)