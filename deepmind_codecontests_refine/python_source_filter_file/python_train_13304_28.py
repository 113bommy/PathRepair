l, r = list(map(int, input().split()))
# if r-l >=2019:
# 	print(0)
# else:
x= [i*j%2019 for i in range(l,r) for j in range (i+1,r+1)]
x.sort()
print(x[0])