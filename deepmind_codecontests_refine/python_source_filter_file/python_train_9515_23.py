#! /usr/bin/env python3

n_len = int(input())
seq = input().split()
seq = [int(i) for i in seq]

def get_sum(lst):
    og_sum = 0
    for i in lst:
        og_sum += i
    return og_sum

def flip(b):
    b = 1 - b
    return b

# calculate original sum
og_sum = get_sum(seq)
list_of_sums = [og_sum]
#print(list_of_sums)


#print('og',seq)
for i in range(n_len):
    end = i + 1
    while end <= n_len:
        new_seq = seq[:]
        #print('new-og',new_seq)
        #print('while_seq',seq)
        #print(i, end)
        for f in range(i,end):
            new_seq[f] = flip(new_seq[f])
        new_sum = get_sum(new_seq)
        #print(new_seq, new_sum)
        list_of_sums.append(new_sum)
        end += 1
#print('OG', seq)
#print(list_of_sums)
print(max(list_of_sums))


