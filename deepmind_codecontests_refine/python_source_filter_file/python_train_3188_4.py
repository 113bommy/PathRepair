c = [int(q) for q in input().split()]
n = c[0]
k = c[1]

a  = 1
i = 0




while n%10==0:
        if (i>=k):
                break

        n /=10
        a*=10
        i+=1
while n%5==0:
        if (i>=k):
                break

        n/=5
        a*=10
        i+=1
while n%2==0:
        if (i>=k):
                break

        n/=2
        a*=10
        i+=1
while i<k :
        i+=1
        a*=10
print(n*a)
