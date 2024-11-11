n , m = map(int,input().split())
l=[]
summ = 0

for i in range(m):
    x ,y = map(int,input().split())
    l.append([x,y])

l.sort(key = lambda y :y[1] ,reverse=True)

for i in range(m):
    a = l[i][0]
    b = l[i][1]
    if n >= a :
        summ += a*b
        n -= a

    elif n < a :
        summ += n*b
        break

print(summ)
