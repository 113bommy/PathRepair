N = int(input())

n = [0]*(N+1)
for i in range(2, N+1):
    for j in range(2, i+1):
        while i%j == 0:
            i//=j
            n[j] += 1

def num(m):
return len(list(filter(lambda x: x>=m-1, e)))

print(num(75)+num(25)*(num(3)-1)+num(15)*(num(5)-1)14+num(5)*(num(5)-1)*(num(3)-2)//2)