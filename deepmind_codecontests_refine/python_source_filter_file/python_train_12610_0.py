n = int(input())
s = input()
num1 = s.count("0")
num2 = s.count("1")
num3 = n - num1 - num2
nums = [num1,num2,num3]
n2 = n // 3
s2= list(s)
for i in range(n):
    if nums[int(s[i])] > n2:
        temp1 = (int(s[i]) + 1) % 3
        temp2 = (int(s[i]) + 2) % 3
        temp3 = min(temp1,temp2)
        temp4 = max(temp1,temp2)
        if nums[temp3] < n2 and temp3 < int(s[i]):
            nums[temp3] += 1
            nums[int(s[i])] -= 1
            s2[i] = temp3
        elif nums[temp4] < n2 and temp3 < int(s[i]):
            nums[temp4] += 1
            nums[int(s[i])] -= 1
            s2[i] = temp4
for i in range(n-1,-1,-1):
    if nums[int(s2[i])] > n2:
        temp1 = (int(s2[i]) + 1) % 3
        temp2 = (int(s2[i]) + 2) % 3
        temp3 = max(temp1,temp2)
        temp4 = min(temp1,temp2)
        if nums[temp3] < n2 :
            nums[temp3] += 1
            nums[int(s2[i])] -= 1
            s2[i] = temp3
        elif nums[temp4] < n2:
            nums[temp4] += 1
            nums[int(s2[i])] -= 1
            s2[i] = temp4
for i in range(n):
    print(s2[i], end = "")
