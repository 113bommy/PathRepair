def cardConstructions(n):
    count = 0 
    i = int(n**0.5)
    if n==2 or n==3:
        return 1
    elif n==1:
        return 0
    else:
        while n>=2:
            if n-(3*(1/2)*(i**2))+(1/2)*i>=0:
                count+=1
                n = n-(3*(1/2)*(i**2))+(1/2)*i
                i = int(n**0.5)
            else:
                i-=1
        return count

for i in range(int(input())):
    n = int(input())
    print(cardConstructions(n))
