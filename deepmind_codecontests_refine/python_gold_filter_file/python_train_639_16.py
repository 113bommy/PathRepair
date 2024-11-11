n, m, k = map(int, input().split())
 
specials = list(map(int, input().split()))
 
pointer = k
 
turn = 0
pop_count = 0
lookup = 0
while specials:
    if specials[lookup] > pointer:
        pointer += ((specials[lookup] - pointer + k - 1) // k) * k
    while specials[lookup] <= pointer:
        lookup += 1
        pop_count += 1
        if lookup == m:
            break
    turn += 1
    pointer += pop_count
    pop_count = 0
    if lookup == m:
        break
 
print(turn)
