# import sys

# sys.stdin = open("input.txt","r")
# sys.stdout = open("output.txt","w")


test = int(input())
for i in range(test):
    size,x = map(int,input().split())

    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    b = b[::-1]
    if i != test-1:
        z = input()
    
    flag = True
    for j in range(size):

        num1 = a[j]
        num2 = b[j]
        if num1 + num2 > x:
            print("No")
            flag = False
        break
    if flag == True:
        print("Yes")


    
    