import array as arr

A_list=[]
B_list=[]
A_count=int(input())
A_arr=[]
A_arr=input().split(" ")
B_count=int(input())
B_arr=[]
B_arr=input().split(" ")
# print(A_arr)
# print(B_arr)
for i in A_arr:
    A_list.append(int(i))

for i in B_arr:
    B_list.append(int(i))

# print(A_list)
# print(B_list)

# creating array as integer type
A=arr.array('i',A_list)
B=arr.array('i',B_list)

res_list = A_list + B_list
# print(res_list)
# print(len(A_list),len(B_list))
# print("AMS")

if(len(A_list)<=len(B_list)):
    for i in A_list:
        for j in B_list:
            Sum=i+j
            if Sum not in res_list:
                print(i,j)
                break
        
        break
else:
    for i in B_list:
        for j in A_list:
            Sum=i+j
            if Sum not in res_list:
                print(j,i)
                break
        
        break
    