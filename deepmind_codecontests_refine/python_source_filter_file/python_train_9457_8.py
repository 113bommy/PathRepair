n=int(input())
a=[int(input()) for i in range(n)]
if sum(a) %10 != 0:
    print(sum(a))
    exit()
for i in a:
    if i%10 != 0:
        print(sum(a)-i)
        exit()
print(0)