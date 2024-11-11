d = int(input())
nu = "12345678910"
ex = 11
while len(nu) < d:
    nu += str(ex)
    ex += 1
print(nu[d-1])