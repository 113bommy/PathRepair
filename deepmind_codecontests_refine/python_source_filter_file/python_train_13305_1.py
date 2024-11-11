a,b = list(map(int,input().split()))
print(a+b if b%a == 0 else a-b)