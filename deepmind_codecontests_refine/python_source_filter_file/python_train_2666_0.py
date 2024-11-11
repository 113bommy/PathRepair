# bsdk idhar kya dekhne ko aaya hai, khud kr!!!
# from math import *
# from itertools import *
# import random
n = int(input())
s = input().split(" ")
count = []
for i in s:
    count_ = 0
    for j in i:
        if j.isalpha():
            if j.upper() == j:
                count_ += 1
            else:
                continue
    count.append(count_)
print(min(count))
