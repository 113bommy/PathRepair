n, k, l, c, d, p, nl, np = map(int, input().split())

toast = []
drink = k * l / nl
lime = c * d
salt = p / np

toast.append(drink)
toast.append(lime)
toast.append(salt)

toast.sort()

print(int(toast[0] // n))