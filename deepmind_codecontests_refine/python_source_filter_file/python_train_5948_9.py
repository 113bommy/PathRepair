n = int(input())

t = input()

result = []

i = 0
delta =1
while i<n:
    print(i,"i")
    result.append(t[i])
    i+=delta
    print(i)
    delta+=1
    print(delta)
print("".join(result))