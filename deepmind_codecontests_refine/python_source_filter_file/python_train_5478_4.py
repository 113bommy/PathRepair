x = 0
n = int(input())
A=[0]*101
while x<n:
    a = int(input())
    for i in range (101):
        if i == a:
            A[i] += 1
    x += 1
kol = 0
summ = 0
B=[]
index1 = index2 = 0
for i in range(101):
    if A[i] >0:
        B.append(A[i])
        index2 = index1
        index1 = i        
        kol += 1
        summ += A[i]
if kol == 2 and summ == n:
    print ('YES\n',index1,index2)
else:
    print ('NO')
    
    