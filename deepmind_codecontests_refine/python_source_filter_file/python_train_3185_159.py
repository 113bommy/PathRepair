def years(limak, bob):
    counter=0
    while limak < bob:
        limak = limak * 3
        bob = bob * 2
        counter+=1
    return counter

inp = list(map(int, input().rstrip().split()))
print(years(inp[0], inp[1]))
