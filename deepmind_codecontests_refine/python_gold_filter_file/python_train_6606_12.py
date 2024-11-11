# link: https://codeforces.com/contest/476/problem/B
import copy
if __name__ == "__main__":
    s1 = input()
    s2 = input()
    final_destination = 0
    for symbol in s1:
        if symbol == '+':
            final_destination += 1
        else:
            final_destination -= 1
    # Now I have final destination
    # Find all possible routes in s2
    possible_destination = [0]
    for symbol in s2:
        if symbol == '+':
            possible_destination = [ 1+i for i in possible_destination ]
        elif symbol == '-':
            possible_destination = [ i-1 for i in possible_destination ]
        else: # symbol == '?'
            values = []
            for num in possible_destination:
                values.append(num+1)
                values.append(num-1)
            possible_destination = copy.deepcopy(values)
    count_value = possible_destination.count(final_destination)
    if count_value == 0:
        print(0)
    else:
        result = (count_value / len(possible_destination))
        print(round(result,9))                

