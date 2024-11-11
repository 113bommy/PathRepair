a, b = list(map(int,input().split()))
list1 = [ ]
for x in range(b):
    if a % 10 != 0:
       a-=1
    else:
       a = a/10
print(a)