expn = input()
nums = ""
result = ""
for i in expn:
    if expn.isdigit():
        nums += i
for i in sorted(nums):
    result += i + "+"
print(result[:-1])
        