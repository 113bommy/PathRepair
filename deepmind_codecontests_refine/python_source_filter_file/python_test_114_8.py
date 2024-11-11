# Author : Ghulam Junaid
for i in range(int(input())):
    lenn = int(input())
    list1 = list(map(int,input().split()))
    list1.sort()
    for i in range(1,lenn//2+1):
        print(list1[0],list1[i])
