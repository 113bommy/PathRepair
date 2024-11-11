
n,b = [int(s) for s in input().split()]
a  = [int(s) for s in input().split()]

x = (sum(a) + b)/n
l = []
for i in a:
    if(x > i):
        l.append(x-i)
    if(x < i):
        print("-1")
        exit()
for i in l:
    print(i)