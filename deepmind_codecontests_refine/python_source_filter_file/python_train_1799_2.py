# arr=[]
# for i in range(1,35):
#     arr.append(2**i-1)
# temp=[]
# for i in arr:
#     temp.append(i*(i+1)/2)
# res=[temp[0]]
# for i in range(1,len(temp)):
#     res.append(res[-1]+temp[i])
# print(res)
import sys
input=sys.stdin.readline
for _ in range(int(input())):
    n=int(input())
    p=1
    temp=n
    count=0
    sumi=0
    while True:

        p=p*2
        sumi=p*(p-1)/2
        # print("p=",p)
        # print("sumi=",sumi)
        # print("temp=",temp)

        temp-=sumi
        if temp<0:
            print(count)
            break
        count+=1
