m=int(input())
a=sum([int(x)%2 for x in input().split()])
print(min(m,abs(a-m)))