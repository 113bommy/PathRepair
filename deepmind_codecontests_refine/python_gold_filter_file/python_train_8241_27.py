query=int(input())
for i in range(query):
    x=input()
    x=x.split(" ")
    n=int(x[0])
    m=int(x[1])
    if n>=(10*m):
        x=10*m
        digits=0
        result=0
        newm=m
        while newm < x:
            digits+=(newm%10)
            newm+=m
        result+=digits*((n//m)//10)
        #start from ((n//m)//10) to n
        x=(n-((n//m)//10)*10*m)
        digits=0
        newm=m
        while newm <= x:
            digits+=(newm%10)
            newm+=m
        #if(n%m==0)
        result+=digits
        print(result)
    elif n<m:
        print(0)
    elif n==m:
        print(m%10)
    else:
        result=0
        x=m*(n//m)#mod?
        newm=m
        while newm <= x:
            result+=(newm%10)
            newm+=m
        print(result)
