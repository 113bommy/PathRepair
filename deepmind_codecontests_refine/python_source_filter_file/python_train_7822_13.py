n = int(input())
a = [int(x) for x in input().split()]
answ = ""
smax = -float('inf')

l = 0
r = len(a) - 1

while l <= r:
    
    if a[l] < a[r]:
        if a[l] > smax:
            answ += 'L'
            smax = a[l]
            l += 1
        elif a[r] > smax:
            answ += 'R'
            smax = a[r]
            r -= 1
        else:
            break
    else:
        if a[r] > smax:
            answ += 'R'
            smax = a[r]
            r -= 1
        elif a[l] > smax:
            answ += 'L'
            smax = a[l]
            l -= 1
        else:
            break

print(len(answ))
print(answ)