n = int(input())
st = input()

carry = 1
nums = 0
for i in range(n):
    if st[i] == '1' and carry == 1:
        carry = 1
        #st[i] = '0'
        nums+=1
    elif st[i] == '0' and carry == 1:
        carry = 0
        nums+=1
    elif (st[i] == '1') and carry == 0:
        carry = 0
        
    else:
        carry = 0
print(nums)