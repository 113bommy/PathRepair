a, b = map(int, input().split())

if a>b:
    diff = b
    same = (a-b)//2
elif a<b:
    diff = a
    same = (b-a)//2
else:
    diff = a//2
    same = 0

print(str(diff)+" "+str(same))