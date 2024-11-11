#B. Люба и билет

def solution():
    s = input()
    a = [int(i) for i in s[:3]]
    b = [int(i) for i in s[3:]]
    
    if sum(b) == sum(a):
        print(0)
        return
    
    if sum(a) > sum(b):
        a, b = b, a
    
    dt = sum(b) - sum(a)
    diffs = []
    for i in a:
        diffs.append(i - 9)
    
    diffs.extend(b)
    diffs.sort(reverse = True)
    i = 0
    while dt > 0:
        dt -= diffs[i]
        i += 1
    print(i)
    
    
solution()