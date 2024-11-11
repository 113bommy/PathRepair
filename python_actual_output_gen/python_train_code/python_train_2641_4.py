n = input()

def steps_of_sum(n, i=0):
    if len(n) == 1:
        return i + 1
    return steps_of_sum(
        str(sum([int(x) for x in str(n)])),i+1
    )

print(steps_of_sum(n))