a=int(input())
b=int(input())
p=len(format(b,"2"))
print(2**p+b*(max(a-p,0)))