x1 = input()
x = [int(i) for i in input().split()]
print(str(abs(x[0]-x[1]))+" "+str(abs(x[0]-x[-1])))
for nums in range(1,len(x)-1):
    print(str(min(abs(x[nums]-x[nums-1]),abs(x[nums]-x[nums+1])))+" "+(str(max(abs(x[nums]-x[-1]),abs(x[nums]-x[0])))))
print(str(abs(x[-1]-x[-2]))+" "+str(abs(x[-1])-x[0]))
