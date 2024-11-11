X=int(input())

for a in range(-200,201):
    for b in range(-200,201):
        if a^5 - b^5 == X:
            print(a,b)
            exit()