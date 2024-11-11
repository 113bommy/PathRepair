#598A
#educational round
#tricky sums
#by greatmom
#copy the first three lines from benji

a=int(input())
for i in range(a):
    b = int(input())
    sum=(b*(b+1))//2

    n=0
    negsum=0
    while (2**n)<=b:
        negsum=negsum+(2**n)
        n=n+1

total = sum - 2*negsum

print(total)
