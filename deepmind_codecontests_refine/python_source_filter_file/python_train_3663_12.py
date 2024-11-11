n = int(input())
a = list(map(int,input().split()))
b = []

for i in range(n):
    b.append([a[i],i])

b.sort(reverse=True)

x = 0
s = 0

for i in b:
   s += i[0]*x 
   x += 1

print(s)

for i in b:
    print(i[1]+1,end=" ")

print()