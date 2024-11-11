n = int(input())
# p,q = map(int,input().split())
a=0
for i in range(n):
    p, q = map(int, input().split())
    if p<q:
    #if (q-p)>=2:
        a = a+1
print(a)




