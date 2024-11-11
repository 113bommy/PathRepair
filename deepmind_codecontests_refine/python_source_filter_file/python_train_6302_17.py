d = int(input())
nu = "012345678910"
ex = 11
while len(nu) < d:
    nu += str(ex)
    ex += 1
print(nu[d-1])
