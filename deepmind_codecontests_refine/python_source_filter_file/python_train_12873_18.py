k, n, s, p = map(int, input().split())
sheets_per_person = (n + s) // s
sheets = k * sheets_per_person
print((sheets + p - 1) // p)