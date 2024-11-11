def split(s):
    for i in  range(len(s)):
        if s[i]==" ":
            return i
            
n = int(input())

s1 = input()
i = split(s1)
min1 = int(s1[0:i])
max1 = int(s1[i+1:])


s2 = input()
i = split(s2)
min2 = int(s2[0:i])
max2 = int(s2[i+1:])

s3 = input()
i = split(s3)
min3 = int(s3[0:i])
max3 = int(s3[i+1:])

x = max1+max2+max3
a = max1
b = max2
c = max3
if x>n and c!= min3:
    x = x - max3 + min3
    c = min3
    
if x>n and b!= min2 and c == min3:
    x = x - max2 + min2
    b = min2
        
if x>n and a != min1 and b==min2 and c== min3:
    x = x - max1+ min1
    a = min1
        
while x<n and min1<=a<max1:
    x = x+1
    a = a+1
    
while x<n and min2<=b<max2:
    x = x+1
    b = b+1
    
while x<n and min3<=c<max3:
    x = x+1
    c = c+1
            
print(a,b,c)