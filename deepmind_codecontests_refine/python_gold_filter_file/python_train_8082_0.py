n=int(input())
a=map(int,input().split())
odd=0
even=0
for x in a:
    if(x%2==1):
        odd=odd+1
    if(x%2==0):
        even=even+1
if(odd<even):
    even=odd;
odd=odd-even
print(even+int(odd/3))