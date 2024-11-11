n=int(input())

a = list(map(int,input().split()))

a.sort()

query = []

high = a[-1]

low = a[0]

for i in range(1,n-1):
    if a[i] > 0:
        query.append([low, a[i]])
        low -= a[i]
    else:
        query.append([high, a[i]])
        high -= a[i]

query.append([high, low])

print(high-low)

for x,y in query:
    print(x,y)

