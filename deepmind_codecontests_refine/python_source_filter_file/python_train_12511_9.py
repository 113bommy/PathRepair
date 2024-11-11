import math

n, k = input().split()
n = int(n)
k = int(k)

solfound = 0
m = 0
x0 = 0

# while not solfound:
#     x0 = k + m - ((n-m)*(n-m+1))/2
    
#     if x0 >=0 and x0%1==0:
#         solfound = 1
#     elif m == 100000000000000:
#         break
#     else:
#         m += 1
        
if (3+2*n+math.sqrt((3+2*n)**2-4*(n+n**2-2*k)))/2 < n:
    m1 = (3+2*n+math.sqrt((3+2*n)**2-4*(n+n**2-2*k)))/2
else:
    m1 = (3+2*n-math.sqrt((3+2*n)**2-4*(n+n**2-2*k)))/2

    
print(m1)

#Check:
# print(k,(n-m)*(n-m+1)/2-m)
# # print(k,m^2-(2*n+3)*m+n+n^2)
# print(2*k,(n*(n-m+1)-m*(n-m+1))-2*m)
# print(2*k,m**2-(2*n+3)*m+n+n**2)
# # print((n-m1)*(n-m1+1)/2-m1)