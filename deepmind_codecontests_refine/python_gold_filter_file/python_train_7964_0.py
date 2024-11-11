n = int(input())
l = [int(i) for i in input().split(" ")]

new = [None] * n
#print(new)
for i in range(n):
    new[l[i]-1] = i
    #print(new)

s = 0
x = new[0]
for i in range(1, n):
   s += abs(x - new[i])
   x = new[i]
print(s)
