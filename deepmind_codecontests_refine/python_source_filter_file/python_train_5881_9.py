n = int(input())
a = input()
b = input()
print(sum((lambda v: min(v,5-v))(abs(ord(i)-ord(j))) for i,j in zip(a,b)))