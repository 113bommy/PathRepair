n,h = map(int,input().strip().split())
bottles = [int(i) for i in input().strip().split()]
import heapq
b_list = []
can = True
def the_sort(the_list,k):
    new_list = []
    insert = 0
    need_sort = False
    for i in range(len(the_list)):
        #print(the_list[i])
        if the_list[i] < k:
            insert = i
            need_sort = True
            break
    index = insert
    if not need_sort:
        the_list.append(k)
        return
    current = k
    while index < len(the_list):
        temp = the_list[index]
        the_list[index] = current
        current = temp
        index += 1
    the_list.append(temp)
for i in range(n):
    max_k = i
    the_sort(b_list,bottles[i])
    #print(b_list,i)
    largest = b_list[0]
    index = 0
    remain = h
    while index <= i:
        remain -= largest
        if remain < 0:
            can = False
            break
        index += 1
        if index < i:
            index += 1
        else:
            break
        largest = b_list[index]
    if not can:
        break
    
print(max_k if not can else n)
