def GCD(x,y):
    r = x%y
    if r == 0:
        return y
    else:
        return GCD(y,r)


n = int(input())
list1 = list(map(int,input().split()))
result = list1[0]
for i in list1[1:]:
    result = result*i/GCD(i,result)

print(result)