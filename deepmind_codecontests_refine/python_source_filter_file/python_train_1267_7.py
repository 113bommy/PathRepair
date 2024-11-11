input1 = list(map(int,input().split()))
input2 = list(map(int,input().split()))
for i in range(input1[0]):
    if input2[i] == min(input2[max(0,i - input1[1]):min(input1[0],i + input1[2]+1)]):
        print(i)
        quit()
    
        