a, b = map(int, input().rstrip().split())
c = a//b
print(c*(c-1)//2+a%b*c, (a-b+1)*(a-b)//2)