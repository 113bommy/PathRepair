#!/usr/bin/python
    
import sys
n , k = list(map(int,input().split(' ')))
brackets = input()
count = [0 for i in range(n + 1)]
paired = [0 for i in range(n)]
inside = 0
queue = []
for i in range(1,n + 1):
    j = i - 1
    count[i] = count[i - 1] + (1 if (brackets[i - 1]=='(') else -1)
    if brackets[j] == '(':
        queue.append(j)
        inside += 1
    else:
        t = queue.pop() 
        inside -= 1
        paired[j] = t
        paired[t] = j
print(paired)
index = 0;
S = ''
while k > 0:
    next_index = paired[index]
    if next_index + 1 <= k + index:
        S += brackets[index : next_index + 1]
        k -= next_index - index + 1
        index = next_index + 1
    else:
        index+=1
    #print(S)
    #print(index)
    #print(next_index)
    #print(count)
    #print(brackets)
print(S)
   # for i in range(n - k + 1):
   #     if (count[i] == count[i + k]) and (brackets[i] == '('):
   #         print(brackets[i:i + k])
   #         break
