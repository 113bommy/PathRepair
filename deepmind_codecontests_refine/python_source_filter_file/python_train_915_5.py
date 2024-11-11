N = int(input())
a = list(map(int,input().split()))

b = []
s = int(sum(a)/len(a))
for i in range(len(a)):
    b.append(abs(a[i]-s))

print(b.index(min(b)))
