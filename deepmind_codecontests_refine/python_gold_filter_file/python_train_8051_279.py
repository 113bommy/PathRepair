k=int(input())
mas = list(map(int,input().split(" ")))
x=sum(mas)/k
print(float('{:.23f}'.format(x)))
