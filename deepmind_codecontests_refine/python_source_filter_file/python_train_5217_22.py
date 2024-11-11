n = int(input())

diff = n-10

if diff <= 0 or diff>11:
    print(0)
elif diff >0and diff<10:
    print(4)
elif diff ==10:
    print(15)
elif diff==11:
    print(1)