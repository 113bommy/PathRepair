n, m, c = [i for i in input().split()]
n = int(n)
m = int(m)
office = []
deputy = set()

k = 0
line = list("." * (m + 2))
office.insert(0, line)
while k < n:
    line = list(input())
    line.insert(0, ".")
    line.append(".")
    office.append(line)
    k += 1
line = list("." * (m + 2))
office.append(line)

i = 1
while i < n:
    j = 1
    while j < m:
        if office[i][j] == c:
            if office[i][j+1] != c:
                deputy.add(office[i][j+1])
            if office[i+1][j] != c:
                deputy.add(office[i+1][j])
            if office[i][j-1] != c:
                deputy.add(office[i][j-1])
            if office[i-1][j] != c:
                deputy.add(office[i-1][j])
        j += 1
    i += 1

deputy.add(".")
deputy.remove(".")
print(len(deputy))
