cases = int(input())
N = [int(input()) for _ in range(cases)]
seats = []

for n in N:
    seats.append(str(2*(n+i)) + " " for i in range(n))

for s in seats:
    print("".join(s))
