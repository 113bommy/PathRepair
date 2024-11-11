n=int(input())

if(n%2!=0):
    n=n-1
    output="b"
else:
    output=""
ch="aa"
for i in range(0,n,2):
    print(output)
    output+=ch
    if(ch=="aa"):
        ch="bb"
    else:
        ch="aa"
print(output)
        
    
    
    