n = int(input())

times = list(map(int, input().split()))

a = 0
b = n - 1

alice = times[0]
bob = 0

alice_count = 1
bob_count = 0

while b - a > 1:
    if bob >= alice:
        a += 1
        alice += times[a]
        alice_count += 1
    else:
        b -= 1
        bob += times[b]
        bob_count += 1

print(alice_count, bob_count)
