n = int(input())
ret = (n-1)//11*2+1
if n%11 > 6: ret += 1
print(ret)
