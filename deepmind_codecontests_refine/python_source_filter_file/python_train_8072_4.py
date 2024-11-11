n = int(input())
arr = list(map(int,input().split()))

i = 0
j = n - 1
bob = alice = 0
a = arr[i]
b = arr[j]
while i <= j:

    if a > b:
        a -= b
        j -= 1
        b = arr[j]
        bob += 1
    elif b > a:
        b -= a
        i += 1
        a = arr[i]
        alice += 1
    else:
        if i < j - 1:
            i += 1
            j -= 1
            a = arr[i]
            b = arr[j]
            bob += 1
            alice += 1
        else:
            alice += 1
            break
print(alice,bob)
