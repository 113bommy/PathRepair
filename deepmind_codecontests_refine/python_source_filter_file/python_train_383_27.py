n=int(input())
a=[int(x) for x in input().split()]
even=0
odd=0
for i in range(len(a)):
    j=i+1
    odd=odd+abs(2*j-1-a[i])
    even=even+abs(a[i]-2*j)
print(min(even,odd))
