def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    # divisors.sort()
    return divisors

input1 = input()
input2 = input()

N = int(input1.split()[0])
K = int(input1.split()[1])

nums = [int(s) for s in input2.split()]

divs = make_divisors(sum(nums))

possible = []

for i in divs:
    nord = [s%i for s in nums]
    nord.sort()
    mt_size = sum(nord) // i
    moves = sum(nord[0:N-mt_size])
    if moves <= K:
        possible.append(i)

print(int(max(possible)))