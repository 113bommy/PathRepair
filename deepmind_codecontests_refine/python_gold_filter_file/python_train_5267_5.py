# - *- coding: utf- 8 - *-
"""
Created on Sun Mar 19 12:39:50 2017

Name: MD. Khairul Basar
Phone: 01760446942
Email: khairul.basar93@gmail.com
"""

n,k = map(int,input().split());
effective = input().split();

array = list();
values = list();
lower_case = "abcdefghijklmnopqrstuvwxyz";
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

for i in range(2):
    for j in range(26):
        if(i != j):
            value = upper_case[i] + lower_case[j];
            values.append(value);
for i in range(n):
    array.append(values[i]);
for i in range(n-k+1):
    if(effective[i] == "NO"):
        array[i+k-1] = array[i];
for i in range(n):
    print("%s "%array[i],end="");
print();