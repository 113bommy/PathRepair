# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.


def exp(x,n):
    # print(x,n)
    if n == 0:
        return 1
    res = exp(x,n//2)
    if n%2:
        return res * res * x
    else:
        return res* res


def find_combos(n):
    parking_slots = 2*n - 2
    #case1
    first_place_combos = 1 * 3 * exp(4,parking_slots-n-1)
    #case2
    last_place_combo = 1 * 3 * exp(4,parking_slots-n-1)
    if parking_slots-n-1 == 0:
        return first_place_combos*2*4
    #case3 
    num_of_choosing_n_succ =  parking_slots - n -1
    middle_cases = num_of_choosing_n_succ - 2
    total_combos = 3 * 3 * middle_cases * exp(4,parking_slots-n-2)
    
    return 4 * (first_place_combos + last_place_combo + total_combos)
    
    
    
n = int(input())
print(find_combos(n))