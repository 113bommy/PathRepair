n,a,b = list(map(int,input().split()))
l = list(map(int,input().split()))
l.sort(reverse=True)
x = l[a-1]
y = l[b-1]
print(x-y)
            


