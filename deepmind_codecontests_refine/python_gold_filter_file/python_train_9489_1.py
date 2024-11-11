import random as rd

def is_sorted(array):
    for i in range(len(array)-1):
            if(array[i] > array[i+1]):
                    return i+1
    return 0
n = input()

a = [int (i) for i in input().split()]
def thanos_sort(array):
    while is_sorted(array):
            i = is_sorted(array)
            target_l = (len(array))//2
            while len(array) > target_l:
                    if(i < target_l):
                            del array[0]
                    else:
                            del array[len(array)-1]
    return array
thanos_sort(a)
print(len(a))
