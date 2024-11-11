a,s = map(int,input().split())
for i in range(s):
    if (a%10==0):
        a = a/10
    else:
        a = a-1
print(a)
