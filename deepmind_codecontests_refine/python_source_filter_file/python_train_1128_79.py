N = int(input())
A = list(map(int,input().split()))
B = [x//400 for x in A]
a,b = 0,0
for i in range(13):
    if i < 8:
        if i in B:
            a+=1
    else:
        b+=B.count(i)
print(a,a+b)
