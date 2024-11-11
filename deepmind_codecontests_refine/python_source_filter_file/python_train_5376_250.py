n = int(input())
m = int(input())
if m < 2**n:
    print(m%(2**n))
else:
    print(m)