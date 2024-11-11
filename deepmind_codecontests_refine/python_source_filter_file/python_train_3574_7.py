import sys

if __name__ == '__main__':
    #reading input
    total, required_median = [int(n) for n in input().split()]
    numbers = [int(n) for n in input().split()] 
    #---------------

    bigger = 0    #number of nums that are bigger than the given median 
    smaller = 0   #number of nums that are smaller than the given median
    same = 0   #number of nums that are equal to the given median
    found = 0 #flag that shows if expected median was found in initial list. Turns to 1 if found
    numbers_to_add = 0 #result to be output
    
    #iterate through the list of numbers we have
    for num in numbers:
        if num > required_median: 
            bigger += 1
        elif num < required_median:
            smaller += 1
        elif num == required_median:
            same += 1
    
    if same == 0: #if no same was found ... we add one therefore adding it to ...
        numbers_to_add += 1 #... the output
        total += 1 #... and the total number of elements in our list
    else:
        same -= 1 #we remove that element from the number of "same" because this will be our median

    diff = abs(bigger - smaller) #we calculate the difference we have between the number of nums bigger and smaller than median

    if bigger > smaller: #if we have more bigger elements than smaller
        smaller = smaller + min(same, diff) #we will consider the equal elements that we have to be part of the smaller
        same = same - min(same, diff) #we naturally subtract the number we got from the equal
        to_add = (bigger - smaller - 1) #I noticed that if the bigger == smaller - 1 AND the total is even, the solution stands. Since this will require the minimum number of moves we will see if this will give a solution.
        if (total + to_add)%2 == 0: #we check if we add that amount we will get an even total
            numbers_to_add += to_add #we add the number if that's the case
        else:
            numbers_to_add += to_add + 1 #if it's odd we will have to add one more element to what we already wanted to add
    #same logic here
    elif bigger < smaller:
        bigger = bigger + min(same, diff)
        same = same - min(same, diff)
        to_add = (smaller - bigger)
        if (total + to_add) % 2 != 0:
            numbers_to_add += to_add
        else:
            numbers_to_add += to_add + 1
    if numbers_to_add >= 0:
        print(numbers_to_add)
    else:
        print(0)
