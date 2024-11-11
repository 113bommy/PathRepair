def find(n):
    if n <= 5:
        return n
    else:
        for i in range(1,25):
            if(5*(pow(2,i)-1) < n <= 5*(pow(2,i+1)-1)):  #第i+1轮
                return int((n - 5 * (pow(2,i)-1)+pow(2,i)-1)/pow(2,i))
            
num = int(input())
if find(num) == 1:
    print('Sheldon')
elif find(num) == 2:
    print('Leonard')
elif find(num) == 3:
    print('Penny')
elif find(num) == 4:
    print('Rajesh')
else:
    print('Howard')
    
