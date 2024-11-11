a,b,c = [int(s) for s in input().split(' ')]
temp = [80%i == 0 for i in range(a,b+1)]
print(sum(temp)) 