''' 686a Free icecreams '''
n,x = [int(x) for x in input().split()]
distress = 0
for _ in range(n):
    temp = x
    x+=eval(input())
    print(x)
    if x<=0:
        distress+=1
        x = temp
print(x,distress)