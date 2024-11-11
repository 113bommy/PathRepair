students = int(input())
segment = input().split(' ')
alsegment = list()
for i in range(int(list(segment)[0]),int(list(segment)[1])+1):
    alsegment.append(i)
for i in range(1,students):
    segment = input().split(' ')
    for i in range(int(list(segment)[0]),int(list(segment)[1])):
        if i in alsegment:
            alsegment.remove(i)
print(len(alsegment))