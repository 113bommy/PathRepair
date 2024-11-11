a=int(input())
for i in range(2,a):
        
        if a%i==0:
                while a%i==0:
                          
                     print(int(a),end=' ')
                     a=a/i
print(int(a))
