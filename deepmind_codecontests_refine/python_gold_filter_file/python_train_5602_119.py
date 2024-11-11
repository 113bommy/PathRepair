a,b = map(int,input().split())

print(max(a+b,(a-1)+a, b+(b-1)))