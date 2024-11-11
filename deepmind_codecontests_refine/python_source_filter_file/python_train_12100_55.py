test_cases = int(input())
for i in range(test_cases):
    x,y,a,b= input().split()
    z = int(y)-int(x)
    a=int(a)
    b=int(b)
    l = []
    if (z)%(b+a)==0:
        print(z/(b+a))
    else:
        print('-1')