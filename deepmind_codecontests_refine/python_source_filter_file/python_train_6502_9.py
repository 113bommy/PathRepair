n, m = map(int, input().split())


kmax = int((n-m+1) * (n-m) / 2)

if n % m == 0: # Uniformly
    kmin = int(m * ((n/m * (n/m-1)) / 2))
else:
    temp = int(n/m)
    team1 = n % m  # How many teams have int(n/m)+1 member
    team2 = m - team1  # How many teams have int(n/m) member
    kmin1 = team1 * (((temp+1) * temp) / 2)
    kmin2 = team2 * (((temp-1) * temp) / 2)
    kmin = int(kmin1 + kmin2)
print(kmin, kmax)