n = int(input())
lis = list(map(int,input().split()))
lis.sort()
pi = 3.1415926536
reds = []
blues = []
for i,j in enumerate(lis):
    if i%2==0:
        reds.append(j)
    else:
        blues.append(j)
reds = [x**2 for x in reds]
blues = [x**2 for x in blues]
print((sum(reds)-sum(blues))*pi)