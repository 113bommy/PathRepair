whatever=int(input())
for i in range (whatever) :
    n=int(input())
    spent=0
    while (n>10) :
        k=n-(n%10)
        spent+=k
        n=n-k+(k/10)
print (int(spent+n))
