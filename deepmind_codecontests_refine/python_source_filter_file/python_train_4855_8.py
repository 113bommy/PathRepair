n=int(input())
x1=n
while x1 > 0:
    if n%x1==0: 
        count=0
        x=x1
        while x%2==0:
            x=x/2
            count+=1
        g=1
        count1 = 0
        for  i in range(count):
            g=g*2+1
            count1 += 1
        if x==g:
            print(x*(2**count))
            x1=0
    x1-=1