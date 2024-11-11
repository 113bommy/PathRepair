a, b = map(int, input().rstrip().split())
c = a//b
print((c*(c-1)//2)*b+a%b*c, (a-b+1)*(a-b)//2)