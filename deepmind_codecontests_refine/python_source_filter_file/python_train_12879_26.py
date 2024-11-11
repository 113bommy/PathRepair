a=int(input())
b=input().split()
b=set(b)
b=list(b)
b.sort()
print(b)
try:
    if b.index("0")>=0:
        print(len(b)-1)
except:
    print(len(b))
