input = input().split(" ")
input1,input2 = int(input[0]),int(input[1])
print("YES")
for i in range(input1,input2):
    print(str(i)+' '+str(i+1))
    