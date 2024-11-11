a,b=map(int, input().split())
max=b//x
min=(a+x-1)//x
print(max-min+1)