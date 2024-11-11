# from bisect import bisect_left 
# import collections

def fun(k,s):
    le = len(s)
    lis= list(s)
    l=0
    r=1
    ans=[]
    j=le-1
    number_of_one=0
    count = 0
    # for i in range(len(s)):
    #     if lis[i]=="1":
    #         number_of_one+=1
    # count=0
    arr=[]
    zeros=0
    for i in range(le):
        if lis[i]=="1":
            arr.append(zeros)
            zeros=0
        else:
            zeros+=1

    arr.append(zeros)
    for i in range(len(arr)):
        if i+k >= len(arr):
            break
        left = arr[i]
        right = arr[i+k]
        if k==0:
            count +=left*(left+1)/2
        else:
            count += (left*right+left+right+1)




    return count
 
 
# var1, var2 = [int(x) for x in input().split()]
 
# # var1, var2,var3 = [int(x) for x in input().split()]
# user_input = input().split(' ')
# numbers = [int(x.strip()) for x in user_input] 
# st = input()
# # print(fun(st))
 
 
# print(fun(st))
 
 
 
 
k =input()
st = input()  
 
# print(fun(numbers))
# var1, var2 = [int(x) for x in input().split()]
# user_input = input().split(' ')
# list1 = [int(x.strip()) for x in user_input] 
# # # # fun(st,var1,var2)
# user_input = input().split(' ')
# lsit2 = [int(x.strip()) for x in user_input] 
# # # var2 = input()
print(fun(int(k),st))
 
# ############################################################3###############################
 
# # user_input = input().split(' ')
# # numbers = [int(x.strip()) for x in user_input] 
# # print(fun(numbers))
# ######################################################################################