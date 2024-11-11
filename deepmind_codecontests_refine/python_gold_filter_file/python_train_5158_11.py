def generateSums(num1,num2):
    a = []
    b = []
    for i in range(5):
        a.append(0)
        b.append(0)
    for i in range(num1+1):
        a.append(0)
    for i in range(num2+1):
        b.append(0)
    for i in range(1,num1+1):
        a[i%5] +=1
    for i in range(1,num2+1):
        b[i%5] +=1
    return (a[0]*b[0]+a[1]*b[4]+a[2]*b[3]+a[3]*b[2]+a[4]*b[1])



nums = input().split()
print(generateSums(int(nums[0]),int(nums[1])))
#items = input().split()
