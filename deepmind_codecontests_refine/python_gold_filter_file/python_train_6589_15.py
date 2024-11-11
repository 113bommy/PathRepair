c = int(input())
n = int(input())

def Simple(n,c):
    sum1=0
    sum2=0
    while n>0:
        # print(n)
        if n%10 != 4 and n%10 != 7:
            return "NO"
        if len(str(n)) > c//2:
            sum1+=n%10
        else:
            sum2+=n%10
        n = n//10
    if sum1 == sum2 :
        return "YES"
    else:
        return "NO"

print(Simple(n,c))