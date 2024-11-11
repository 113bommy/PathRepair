import re

first, second = map(int, input().split())
first_str = "{0:b}".format(first)
second_str = "{0:b}".format(second)
rev_first_str = first_str[::-1]

def trim_zeroes(str):
    return str.lstrip("0")

def trim_both_zeroes(str):
    return str.strip("0")

# print(re.fullmatch(f"{trim_zeroes(rev_first_str)}", f"{second_str}"))
# 11111101111110010010101011101110111010010110110011101 11111111101111110010010101011101110111010010110110011101
print(first_str, second_str)
print("YES" if first_str == second_str or re.fullmatch(f"1*({first_str}1|1{rev_first_str}|{trim_zeroes(rev_first_str)}|{trim_both_zeroes(first_str)})1*", f"{second_str}") else "NO")

# # do I need to reverse the second string?
# if first_str == second_str or reversed(first_str) == second_str: print("YES")
# # iterate thru the second string, and
# # if equal number of chars on left and right (plus or minus 1/0), return YES
# # 100010 or 010001
# # 1(010001)

# # 1010001 or 1000101
# # 1000101 


# # you trim the first string of all the 0s
# # first_str = first_str.trim("0")
# n = len(first_str)
# # then check if it or its reversed one is inside
# # and if so, check left and right is 1

# print(first_str, second_str)
# for i in range(len(second_str)):
#     substring = second_str[i:i+n]
#     print("substring", substring)
#     # print(substring, rev_first_str)
#     if substring == first_str or substring == rev_first_str:
#         # print("got it")
#         left = i
#         right = len(second_str) - (i + n)
#         # print(left, right)
#         if abs(left - right) <= 1:
#             print("YES")


# print(first_str, second_str)