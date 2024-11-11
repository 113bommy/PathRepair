def solve(a):
    result = 2 * len(a) - 1
    for i in range(len(a) - 2):
        if not check(a[i:i + 2]):
            result += 1
    for i in range(len(a) - 3):
        if not check(a[i:i + 3]):
            result += 1
    return result
        
    
def check(a):
    first, second = 0, 0
    first_result = False
    for el in a:
        if el >= first:
            first = el
        elif el >= second:
            second = el
        else:
            first_result = True
            break
    first, second = 2**32, 2**32
    second_result = False
    for el in a:
        if el <= first:
            first = el
        elif el <= second:
            second = el
        else:
            second_result = True
            break
    return first_result or second_result
        

for _ in range(int(input())):
    n = int(input())
    x = [int(x) for x in input().split()]
    print(solve(x))